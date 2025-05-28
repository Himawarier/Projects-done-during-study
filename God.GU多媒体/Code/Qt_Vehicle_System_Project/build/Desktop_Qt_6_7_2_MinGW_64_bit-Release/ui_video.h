/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_video
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QToolButton *returnBtn;
    QWidget *controlListWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *openBtn;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *backwordBtn;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *playBtn;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *forwordBtn;
    QSpacerItem *horizontalSpacer;
    QToolButton *volumeBtn;
    QToolButton *zoomBtn;

    void setupUi(QWidget *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName("video");
        video->resize(800, 480);
        gridLayout = new QGridLayout(video);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(video);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-image: url(:/UI/Img/02.bmp);\n"
"}"));
        returnBtn = new QToolButton(widget);
        returnBtn->setObjectName("returnBtn");
        returnBtn->setGeometry(QRect(10, 10, 81, 31));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        returnBtn->setIcon(icon);
        returnBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        returnBtn->setAutoRaise(true);
        controlListWidget = new QWidget(widget);
        controlListWidget->setObjectName("controlListWidget");
        controlListWidget->setGeometry(QRect(0, 430, 800, 50));
        controlListWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(controlListWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        openBtn = new QToolButton(controlListWidget);
        openBtn->setObjectName("openBtn");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        openBtn->setIcon(icon1);
        openBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        openBtn->setAutoRaise(true);

        horizontalLayout->addWidget(openBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        backwordBtn = new QToolButton(controlListWidget);
        backwordBtn->setObjectName("backwordBtn");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekBackward));
        backwordBtn->setIcon(icon2);
        backwordBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        backwordBtn->setAutoRaise(true);

        horizontalLayout->addWidget(backwordBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        playBtn = new QToolButton(controlListWidget);
        playBtn->setObjectName("playBtn");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        playBtn->setIcon(icon3);
        playBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        playBtn->setAutoRaise(true);

        horizontalLayout->addWidget(playBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        forwordBtn = new QToolButton(controlListWidget);
        forwordBtn->setObjectName("forwordBtn");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekForward));
        forwordBtn->setIcon(icon4);
        forwordBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        forwordBtn->setAutoRaise(true);

        horizontalLayout->addWidget(forwordBtn);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        volumeBtn = new QToolButton(controlListWidget);
        volumeBtn->setObjectName("volumeBtn");
        volumeBtn->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
        volumeBtn->setIcon(icon5);
        volumeBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        volumeBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        volumeBtn->setAutoRaise(true);

        horizontalLayout->addWidget(volumeBtn);

        zoomBtn = new QToolButton(controlListWidget);
        zoomBtn->setObjectName("zoomBtn");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::ViewFullscreen));
        zoomBtn->setIcon(icon6);
        zoomBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        zoomBtn->setAutoRaise(true);

        horizontalLayout->addWidget(zoomBtn);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QWidget *video)
    {
        video->setWindowTitle(QCoreApplication::translate("video", "Form", nullptr));
        returnBtn->setText(QCoreApplication::translate("video", "\350\277\224\345\233\236", nullptr));
        openBtn->setText(QCoreApplication::translate("video", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        backwordBtn->setText(QString());
        playBtn->setText(QString());
        forwordBtn->setText(QString());
        volumeBtn->setText(QString());
        zoomBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
