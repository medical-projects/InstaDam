#include "filtercontrols.h"

#include <QtGlobal>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <vector>
#include <iostream>

//#include "filters.h"
#include "pixmapops.h"

#define CONNECTCAST(OBJECT, TYPE, FUNC) static_cast<void(OBJECT::*)(TYPE)>(&OBJECT::FUNC)

/*!
  \class filterDialog
  \ingroup app
  \inmodule InstaDam
  \brief Defines a custom QDIalog based on the selected mask.
  \param selectedMask
  \param fc
  \param photoViewer
  \param currentPro
 */
filterDialog::filterDialog(maskTypes selectedMask, filterControls* fc,
                           PhotoViewer* photoViewer, Project *currentPro)
    : QDialog() {
    qInfo("1");
    size_t numControls = static_cast<size_t>(fc->properties[selectedMask]->numControls);
    this->setWindowTitle("Filter Options");

    QVBoxLayout *VBlayout = new QVBoxLayout(this);
    Project* currentProject = currentPro;
    for (size_t i = 0; i < numControls; i++) {
        QLabel *name = new QLabel();
        name->setText(QString(fc->properties[selectedMask]->propertylist[i]->name));

        QHBoxLayout *HBlayout = new QHBoxLayout();
        HBlayout->addWidget(name);
        threshold_or_filter thof = fc->properties[selectedMask]->propertylist[i]->threshold_filter;
        switch (fc->properties[selectedMask]->propertylist[i]->btnType) {
            case SLIDER:
            {
                fSlider *itemSlider = new fSlider(selectedMask,
                                                  static_cast<int>(i), thof,
                                                  this);
                fSpinBox* itemNumbox = new fSpinBox(selectedMask,
                                                    static_cast<int>(i), thof,
                                                    this);
                connect(itemSlider, SIGNAL(valueChanged(int)), itemNumbox,
                        SLOT(setValue(int)));
                itemSlider->setOrientation(Qt::Horizontal);
                connect(itemNumbox, SIGNAL(valueChanged(int)), itemSlider,
                        SLOT(setValue(int)));

                HBlayout->addWidget(itemSlider);
                HBlayout->addWidget(itemNumbox);

                qInfo("max = %d", fc->properties[selectedMask]->propertylist[i]->max);
                qInfo("3");
                itemSlider->setMaximum(fc->properties[selectedMask]->propertylist[i]->max);
                itemNumbox->setMaximum(fc->properties[selectedMask]->propertylist[i]->max);
                itemSlider->setMinimum(fc->properties[selectedMask]->propertylist[i]->min);
                itemNumbox->setMinimum(fc->properties[selectedMask]->propertylist[i]->min);
                itemNumbox->setValue(fc->properties[selectedMask]->propertylist[i]->val);
                itemSlider->setValue(fc->properties[selectedMask]->propertylist[i]->val);

                connect(itemSlider, SIGNAL(filterValueChanged(maskTypes, int,
                                                              int,
                                                              threshold_or_filter)),
                        fc, SLOT(assignVal(maskTypes, int, int,
                                           threshold_or_filter)));
                connect(itemNumbox, SIGNAL(filterValueChanged(maskTypes, int,
                                                              int,
                                                              threshold_or_filter)),
                        fc, SLOT(assignVal(maskTypes, int, int,
                                           threshold_or_filter)));

                VBlayout->addLayout(HBlayout);
                break;
            }

            case CHECKBOX:
            {
                fCheckBox *itemCBox = new fCheckBox(selectedMask,
                                                    static_cast<int>(i), thof,
                                                    this);
                itemCBox->setCheckState(Qt::CheckState(fc->properties[selectedMask]->propertylist[i]->val));

                connect(itemCBox, SIGNAL(filterValueChanged(maskTypes, int, int,
                                                            threshold_or_filter)),
                        fc, SLOT(assignVal(maskTypes, int, int,
                                           threshold_or_filter)));

                HBlayout->addWidget(itemCBox);
                VBlayout->addLayout(HBlayout);

                break;
            }
            case LABELLIST:
            {
                VBlayout->addLayout(HBlayout);
                for (int i=0; i < currentProject->numLabels(); i++) {
                    QSharedPointer<Label> label = currentProject->getLabel(i);
                    LabelButtonFilter *button = new LabelButtonFilter(label);
                    button->setText(label->getText());
                    QPalette pal = button->palette();
                    pal.setColor(QPalette::ButtonText, Qt::black);
                    pal.setColor(QPalette::Button, label->getColor());
                    button->setAutoFillBackground(true);
                    button->setPalette(pal);
                    button->update();

                    VBlayout->addWidget(button);

                    connect(button, SIGNAL(cclicked(QSharedPointer<Label>)), fc,
                            SLOT(setLabelMask(QSharedPointer<Label>)));
                }
                break;
            }
        }
        connect(fc, SIGNAL(valAssigned(maskTypes, threshold_or_filter)),
                photoViewer, SLOT(setImMask(maskTypes,
                                            threshold_or_filter)));
    }
    QDialog::show();
}

/*!
  \class filterControls
  \ingroup app
  \inmodule InstaDam
  \brief Defines the properties of the mask and conducts the filtering operations
*/

filterControls::filterControls():QObject() {
    defineProperties();
}


/*!
 * \brief filterControls::assignVal is a slot that sets the int \a value
 * to the appropriate property indexed by \a maskType and \a propnNum
 */
void filterControls::assignVal(maskTypes maskType, int propNum, int value,
                               threshold_or_filter thof) {
    this->properties[maskType]->propertylist[static_cast<size_t>(propNum)]->sliderAssign(value);
    emit valAssigned(maskType, thof);
}

/*!
 Obtains the label mask from \a label and sets it to \a labelMask to be used as a mask
 for the LABELMASK filter operation.
 */
void filterControls::setLabelMask(QSharedPointer<Label> label) {
    this->labelMask = label->exportLabel(SelectItem::myBounds);
    emit valAssigned(LABELMASK, FILTER);
}

/*!
 Defines the properties of the different masks.
 */
void filterControls::defineProperties() {
    std::vector<filterProperty*> cannyProperties;

    cannyProperties.push_back(new filterProperty("Invert", CHECKBOX, 0, 2, 1,
                                                 ANY, THRESH, false));
    cannyProperties.push_back(new filterProperty("Threshold min", SLIDER, 0, 60,
                                                 255, ANY, THRESH, false));
    cannyProperties.push_back(new filterProperty("Low", SLIDER, 3, 5, 801, ODD,
                                                 FILTER, false));
    cannyProperties.push_back(new filterProperty("High", SLIDER, 3, 5, 801, ODD,
                                                 FILTER, false));
    cannyProperties.push_back(new filterProperty("Kernal", SLIDER, 3, 5, 7, ODD,
                                                 FILTER, false));

    std::vector<filterProperty*> blurProperties;

    blurProperties.push_back(new filterProperty("Invert", CHECKBOX, 0, 2, 1,
                                                ODD, THRESH, false));
    blurProperties.push_back(new filterProperty("Threshold min", SLIDER, 0,
                                                60, 255, ANY, THRESH, false));
    blurProperties.push_back(new filterProperty("Kernel X", SLIDER, 3, 15, 51,
                                                ODD, FILTER, false));
    blurProperties.push_back(new filterProperty("Kernel Y", SLIDER, 3, 15, 51,
                                                ODD, FILTER, false));
    blurProperties.push_back(new filterProperty("Sigma", SLIDER, 3, 5, 55,
                                                ODD, FILTER, false));

    std::vector<filterProperty*> thresholdProperties;
    thresholdProperties.push_back(new filterProperty("Invert", CHECKBOX, 0, 2,
                                                     1, ANY, THRESH, false));
    thresholdProperties.push_back(new filterProperty("Threshold min", SLIDER, 0,
                                                     60, 255, ANY, THRESH, false));

    std::vector<filterProperty*> labelmaskProperties;
    labelmaskProperties.push_back(new filterProperty("Invert", CHECKBOX, 0, 2, 1,
                                                     ANY, THRESH, false));
    labelmaskProperties.push_back(new filterProperty("Threshold min", SLIDER, 0,
                                                     60, 255, ANY, THRESH, false));
    labelmaskProperties.push_back(new filterProperty("Label List", LABELLIST, 0,
                                                     2, 1, ANY, FILTER, false));

    filterPropertiesMeta *cannyPropertiesMeta =
            new filterPropertiesMeta(cannyProperties, 5, CANNY);
    filterPropertiesMeta *blurPropertiesMeta =
            new filterPropertiesMeta(blurProperties, 5, BLUR);
    filterPropertiesMeta *thresholdPropertiesMeta =
            new filterPropertiesMeta(thresholdProperties, 2, THRESHOLD);
    filterPropertiesMeta *labelmaskPropertiesMeta =
            new filterPropertiesMeta(labelmaskProperties, 3, LABELMASK);

    // Order follows order of enum defined in instadam.h
    properties.push_back(cannyPropertiesMeta);
    properties.push_back(thresholdPropertiesMeta);
    properties.push_back(blurPropertiesMeta);
    properties.push_back(labelmaskPropertiesMeta);
}


/*!
 Filters the cv::Mat \image based on the selected maskTypes \a selectedFilter
 and returns a binary image cv::Mat \a edge_temp
 */
cv::Mat filterControls::filterFunc(cv::Mat image, maskTypes selectedFilter) {
    cv::Mat edge_temp;
    switch (selectedFilter) {
        case CANNY:
            cv::Canny(image, edge_temp, properties[CANNY]->propertylist[2]->val,
                                        properties[CANNY]->propertylist[3]->val,
                                        properties[CANNY]->propertylist[4]->val);
            break;
        case BLUR:
            cv::GaussianBlur(image, edge_temp,
                             cv::Size(properties[BLUR]->propertylist[2]->val,
                                      properties[BLUR]->propertylist[3]->val),
                                      properties[BLUR]->propertylist[4]->val);
            break;
        case THRESHOLD:
            cv::cvtColor(image, edge_temp, cv::COLOR_RGB2GRAY);
            break;
        case LABELMASK:
            if (!this->labelMask.isNull()) {
                QImage image_pixmap(this->labelMask.toImage().convertToFormat(QImage::Format_RGB888));
                cv::Mat mat(image_pixmap.height(), image_pixmap.width(),
                            CV_8UC3, image_pixmap.bits());

                cv::cvtColor(mat, edge_temp, cv::COLOR_RGB2GRAY);
            } else {
                cv::cvtColor(image, edge_temp, cv::COLOR_RGB2GRAY);
            }
            break;
        case OTHER:
            break;
    }
    return edge_temp;
}

/*!
 * Sets image for the object and stores and returns filtered edges.
*/
cv::Mat filterControls::filtAndGeneratePixmaps(cv::Mat image,
                                               maskTypes selectedFilter) {
        img = image;
        edges = filterFunc(img, selectedFilter);
        im2pixmap(selectedFilter);
        return edges;
}

/*!
 * Binarizes the image and converts it to a pixmap
 */
void filterControls::im2pixmap(maskTypes selectedFilter) {
    cv::Mat binary;
    int invert = properties[selectedFilter]->propertylist[0]->val;


    qInfo("%d", invert);
    if (invert == 2)
        cv::threshold(edges, binary, properties[selectedFilter]->propertylist[1]->val,
                255, cv::THRESH_BINARY_INV);
    else
        cv::threshold(edges, binary, properties[selectedFilter]->propertylist[1]->val,
                255, cv::THRESH_BINARY);

    QImage qImgImg = QImage(reinterpret_cast<uchar*>(binary.data), binary.cols,
                            binary.rows, static_cast<int>(binary.step),
                            QImage::Format_Grayscale8);
    this->qImg = QPixmap::fromImage(qImgImg);
    QImage qAlphaImg = QImage(reinterpret_cast<uchar*>(binary.data), binary.cols,
                              binary.rows, static_cast<int>(binary.step),
                              QImage::Format_Alpha8);
    this->qAlpha = QPixmap::fromImage(qAlphaImg);
}

/*!
 * Returns a thubnail pixmap for the filter selection bar at the bottom of InstaDam.
 */
QPixmap filterControls::thumb2pixmap(cv::Mat thumb, maskTypes selectedFilter) {
    qInfo("Enter Thumb");
    cv::Mat thumbEdges = this->filterFunc(thumb, selectedFilter);
    qInfo("Filtered thumbnail!");
    cv::Mat binaryThumb;
    int invert = properties[selectedFilter]->propertylist[0]->val;

    if (invert == 2)
        cv::threshold(thumbEdges, binaryThumb, properties[selectedFilter]->propertylist[1]->val,
                255, cv::THRESH_BINARY_INV);
    else
        cv::threshold(thumbEdges, binaryThumb, properties[selectedFilter]->propertylist[1]->val,
                255, cv::THRESH_BINARY);
    QImage qImgImg_temp = QImage(reinterpret_cast<uchar*>(binaryThumb.data),
                                 binaryThumb.cols, binaryThumb.rows,
                                 static_cast<int>(binaryThumb.step),
                                 QImage::Format_Grayscale8);
    qImgThumb = QPixmap::fromImage(qImgImg_temp);
    return qImgThumb;
}
