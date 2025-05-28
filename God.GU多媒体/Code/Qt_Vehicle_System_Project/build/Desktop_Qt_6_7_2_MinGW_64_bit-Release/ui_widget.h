/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QToolButton *mapBtn;
    QToolButton *daoceBtn;
    QToolButton *musicBtn;
    QToolButton *videoBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 480);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	\n"
"	background-image: url(:/UI/Img/Forza_Horizon_4.bmp);\n"
"}\n"
"QToolButton{\n"
"	\n"
"	font: 9pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        mapBtn = new QToolButton(widget);
        mapBtn->setObjectName("mapBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI/Img/BaiduMap.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mapBtn->setIcon(icon);
        mapBtn->setIconSize(QSize(80, 80));
        mapBtn->setAutoRepeat(false);
        mapBtn->setAutoExclusive(false);
        mapBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        mapBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        mapBtn->setAutoRaise(true);
        mapBtn->setArrowType(Qt::ArrowType::NoArrow);

        verticalLayout->addWidget(mapBtn);

        daoceBtn = new QToolButton(widget);
        daoceBtn->setObjectName("daoceBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/UI/Img/daoce.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        daoceBtn->setIcon(icon1);
        daoceBtn->setIconSize(QSize(80, 80));
        daoceBtn->setAutoRepeat(false);
        daoceBtn->setAutoExclusive(false);
        daoceBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        daoceBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        daoceBtn->setAutoRaise(true);
        daoceBtn->setArrowType(Qt::ArrowType::NoArrow);

        verticalLayout->addWidget(daoceBtn);

        musicBtn = new QToolButton(widget);
        musicBtn->setObjectName("musicBtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/UI/Img/music.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        musicBtn->setIcon(icon2);
        musicBtn->setIconSize(QSize(80, 80));
        musicBtn->setAutoRepeat(false);
        musicBtn->setAutoExclusive(false);
        musicBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        musicBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        musicBtn->setAutoRaise(true);
        musicBtn->setArrowType(Qt::ArrowType::NoArrow);

        verticalLayout->addWidget(musicBtn);

        videoBtn = new QToolButton(widget);
        videoBtn->setObjectName("videoBtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/UI/Img/video.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        videoBtn->setIcon(icon3);
        videoBtn->setIconSize(QSize(80, 80));
        videoBtn->setAutoRepeat(false);
        videoBtn->setAutoExclusive(false);
        videoBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        videoBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        videoBtn->setAutoRaise(true);
        videoBtn->setArrowType(Qt::ArrowType::NoArrow);

        verticalLayout->addWidget(videoBtn);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        mapBtn->setText(QCoreApplication::translate("Widget", "\347\231\276\345\272\246\345\234\260\345\233\276", nullptr));
        daoceBtn->setText(QCoreApplication::translate("Widget", "\345\200\222\350\275\246\345\275\261\345\203\217", nullptr));
        musicBtn->setText(QCoreApplication::translate("Widget", "\346\211\243\346\211\243\351\230\264\344\271\220", nullptr));
        videoBtn->setText(QCoreApplication::translate("Widget", "video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
