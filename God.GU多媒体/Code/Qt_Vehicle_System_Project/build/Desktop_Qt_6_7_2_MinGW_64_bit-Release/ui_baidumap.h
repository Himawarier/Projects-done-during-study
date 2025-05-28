/********************************************************************************
** Form generated from reading UI file 'baidumap.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAIDUMAP_H
#define UI_BAIDUMAP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaiduMap
{
public:
    QLabel *mapLabel;
    QToolButton *returnBtn;
    QScrollBar *mapSizeBar;

    void setupUi(QWidget *BaiduMap)
    {
        if (BaiduMap->objectName().isEmpty())
            BaiduMap->setObjectName("BaiduMap");
        BaiduMap->resize(800, 480);
        mapLabel = new QLabel(BaiduMap);
        mapLabel->setObjectName("mapLabel");
        mapLabel->setGeometry(QRect(0, 0, 800, 480));
        mapLabel->setStyleSheet(QString::fromUtf8("QLabel#mapLabel{\n"
"background-color: rgb(253, 208, 255);\n"
"}"));
        returnBtn = new QToolButton(BaiduMap);
        returnBtn->setObjectName("returnBtn");
        returnBtn->setGeometry(QRect(0, 10, 71, 41));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        returnBtn->setIcon(icon);
        returnBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        returnBtn->setAutoRaise(false);
        returnBtn->setArrowType(Qt::ArrowType::NoArrow);
        mapSizeBar = new QScrollBar(BaiduMap);
        mapSizeBar->setObjectName("mapSizeBar");
        mapSizeBar->setGeometry(QRect(780, 10, 16, 461));
        mapSizeBar->setStyleSheet(QString::fromUtf8("color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        mapSizeBar->setMinimum(3);
        mapSizeBar->setMaximum(18);
        mapSizeBar->setOrientation(Qt::Orientation::Vertical);

        retranslateUi(BaiduMap);

        QMetaObject::connectSlotsByName(BaiduMap);
    } // setupUi

    void retranslateUi(QWidget *BaiduMap)
    {
        BaiduMap->setWindowTitle(QCoreApplication::translate("BaiduMap", "Form", nullptr));
        mapLabel->setText(QCoreApplication::translate("BaiduMap", "TextLabel", nullptr));
        returnBtn->setText(QCoreApplication::translate("BaiduMap", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaiduMap: public Ui_BaiduMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAIDUMAP_H
