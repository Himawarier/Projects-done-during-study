/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Music
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QToolButton *returnBtn;
    QListWidget *songListWidget;
    QWidget *musicControlWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *openBtn;
    QSpacerItem *horizontalSpacer;
    QToolButton *lastBtn;
    QToolButton *playBtn;
    QToolButton *nextBtn;
    QSlider *musicSlider;
    QLabel *timeLabel;
    QToolButton *volumeBtn;
    QWidget *lyricwidget;
    QVBoxLayout *verticalLayout;
    QLabel *songName;
    QLabel *lyric1;
    QLabel *lyric2;
    QLabel *lyric3;
    QLabel *lyric4;
    QLabel *lyric5;

    void setupUi(QWidget *Music)
    {
        if (Music->objectName().isEmpty())
            Music->setObjectName("Music");
        Music->resize(800, 480);
        gridLayout = new QGridLayout(Music);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Music);
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
        songListWidget = new QListWidget(widget);
        songListWidget->setObjectName("songListWidget");
        songListWidget->setGeometry(QRect(10, 40, 271, 371));
        songListWidget->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	/*border-style: none; */\n"
"	background-color: rgba(255, 255, 255, 50); \n"
"}"));
        musicControlWidget = new QWidget(widget);
        musicControlWidget->setObjectName("musicControlWidget");
        musicControlWidget->setGeometry(QRect(0, 430, 800, 50));
        horizontalLayout = new QHBoxLayout(musicControlWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(15, 0, 15, 0);
        openBtn = new QToolButton(musicControlWidget);
        openBtn->setObjectName("openBtn");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        openBtn->setIcon(icon1);
        openBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        openBtn->setAutoRaise(true);

        horizontalLayout->addWidget(openBtn);

        horizontalSpacer = new QSpacerItem(50, 47, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lastBtn = new QToolButton(musicControlWidget);
        lastBtn->setObjectName("lastBtn");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::MediaSkipBackward));
        lastBtn->setIcon(icon2);
        lastBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        lastBtn->setAutoRaise(true);

        horizontalLayout->addWidget(lastBtn);

        playBtn = new QToolButton(musicControlWidget);
        playBtn->setObjectName("playBtn");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        playBtn->setIcon(icon3);
        playBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        playBtn->setAutoRaise(true);

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QToolButton(musicControlWidget);
        nextBtn->setObjectName("nextBtn");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaSkipForward));
        nextBtn->setIcon(icon4);
        nextBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        nextBtn->setAutoRaise(true);

        horizontalLayout->addWidget(nextBtn);

        musicSlider = new QSlider(musicControlWidget);
        musicSlider->setObjectName("musicSlider");
        musicSlider->setEnabled(true);
        musicSlider->setStyleSheet(QString::fromUtf8("/*1.\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"	background-color: rgb(253, 229, 255);		 /*\346\247\275\351\242\234\350\211\262*/\n"
"	border-radius: 2px;											 /*\345\244\226\347\216\257\345\214\272\345\237\237\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
" 	margin-top:8px;												/*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
" 	margin-bottom:8px;										/*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"	/*width\345\234\250\350\277\231\351\207\214\346\227\240\346\225\210\357\274\214\344\270\215\345\206\231\345\215\263\345\217\257*/\n"
"}\n"
"\n"
"/*2.\346\234\252\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::add-page:horizontal \n"
"{\n"
"	background-color:rgb(255, 255, 255);	/*\346\247\275\351\242\234\350\211\262*/\n"
""
                        "	border: 0px solid #777;								/*\345\244\226\347\216\257\345\244\247\345\260\2170px\345\260\261\346\230\257\344\270\215\346\230\276\347\244\272\357\274\214\351\273\230\350\256\244\344\271\237\346\230\2570*/\n"
"	border-radius: 2px;										/*\345\244\226\347\216\257\345\214\272\345\237\237\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"	margin-top:9px;											/*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"	margin-bottom:9px;									/*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"}\n"
" \n"
"/*3.\345\271\263\346\227\266\346\273\221\345\212\250\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal \n"
"{\n"
"	background: rgb(255, 170, 127);			/*\346\273\221\345\235\227\351\242\234\350\211\262*/\n"
"	width: 5px;												/*\346\273\221\345\235\227\347\232\204\345\256\275\345\272\246*/\n"
"	border: 1px solid rgb(193,204,208);	/*\346\273\221\345\235"
                        "\227\345\244\226\347\216\257\344\270\2721px\357\274\214\345\206\215\345\212\240\351\242\234\350\211\262*/\n"
"	border-radius: 2px; 									/*\346\273\221\345\235\227\345\244\226\347\216\257\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"	margin-top:6px;										/*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"	margin-bottom:6px;								/*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"}\n"
"\n"
"/*4.\346\211\213\345\212\250\346\213\211\345\212\250\346\227\266\346\230\276\347\244\272\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal:hover \n"
"{\n"
"	background: rgb(128, 217, 255);/*\346\273\221\345\235\227\351\242\234\350\211\262*/\n"
"	width: 10px;/*\346\273\221\345\235\227\347\232\204\345\256\275\345\272\246*/\n"
"	border: 1px solid rgb(193,204,208);/*\346\273\221\345\235\227\345\244\226\347\216\257\344\270\2721px\357\274\214\345\206\215\345\212\240"
                        "\351\242\234\350\211\262*/\n"
"	border-radius: 5px;  /*\346\273\221\345\235\227\345\244\226\347\216\257\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
" 	margin-top:4px;/*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"	margin-bottom:4px; /*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"}"));
        musicSlider->setMaximum(100);
        musicSlider->setValue(0);
        musicSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(musicSlider);

        timeLabel = new QLabel(musicControlWidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMinimumSize(QSize(40, 26));

        horizontalLayout->addWidget(timeLabel);

        volumeBtn = new QToolButton(musicControlWidget);
        volumeBtn->setObjectName("volumeBtn");
        volumeBtn->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
        volumeBtn->setIcon(icon5);
        volumeBtn->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        volumeBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        volumeBtn->setAutoRaise(true);

        horizontalLayout->addWidget(volumeBtn);

        lyricwidget = new QWidget(widget);
        lyricwidget->setObjectName("lyricwidget");
        lyricwidget->setGeometry(QRect(320, 40, 481, 371));
        lyricwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lyricwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-style: none; \n"
"	background-color: rgba(255, 255, 255, 0); \n"
"}\n"
"\n"
"QLabel \n"
"{ \n"
"	font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"	text-decoration: underline;\n"
"	color: rgb(255, 170, 0); \n"
"	alignment: AlignCenter;    /*\346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220*/\n"
"}\n"
"QLabel#lyric3\n"
"{ \n"
"	color: rgb(109, 5, 255); \n"
"}\n"
"\n"
"QLabel#songName\n"
"{ \n"
"	font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";\n"
"	color: rgb(255, 119, 0); \n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(lyricwidget);
        verticalLayout->setObjectName("verticalLayout");
        songName = new QLabel(lyricwidget);
        songName->setObjectName("songName");
        songName->setMinimumSize(QSize(300, 100));
        songName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(songName);

        lyric1 = new QLabel(lyricwidget);
        lyric1->setObjectName("lyric1");
        lyric1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lyric1);

        lyric2 = new QLabel(lyricwidget);
        lyric2->setObjectName("lyric2");
        lyric2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lyric2);

        lyric3 = new QLabel(lyricwidget);
        lyric3->setObjectName("lyric3");
        lyric3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lyric3);

        lyric4 = new QLabel(lyricwidget);
        lyric4->setObjectName("lyric4");
        lyric4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lyric4);

        lyric5 = new QLabel(lyricwidget);
        lyric5->setObjectName("lyric5");
        lyric5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lyric5);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Music);

        QMetaObject::connectSlotsByName(Music);
    } // setupUi

    void retranslateUi(QWidget *Music)
    {
        Music->setWindowTitle(QCoreApplication::translate("Music", "Form", nullptr));
        returnBtn->setText(QCoreApplication::translate("Music", "\350\277\224\345\233\236", nullptr));
        openBtn->setText(QCoreApplication::translate("Music", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        lastBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        timeLabel->setText(QCoreApplication::translate("Music", "00:00", nullptr));
        volumeBtn->setText(QString());
        songName->setText(QString());
        lyric1->setText(QString());
        lyric2->setText(QString());
        lyric3->setText(QString());
        lyric4->setText(QString());
        lyric5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Music: public Ui_Music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
