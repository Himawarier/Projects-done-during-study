#include "volumepopup.h"


VolumePopup::VolumePopup(QWidget *parent)
    : QWidget{parent}
{

    // 设置窗口为弹出窗口，没有边框，背景透明
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);  //背景透明

    // 创建一个垂直布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 创建一个垂直方向的音量滑块
    volumeSlider = new QSlider(this);
    volumeSlider->setRange(0,100);      // 设置音量滑块的范围为0到100

    layout->addWidget(volumeSlider);     // 将音量滑块添加到布局中
    layout->setContentsMargins(0,0,0,0);   // 移除布局的边距

///////////////////////其实这个定时器和鼠标离开事件只需要一个就够了，作用差不多

    //// 设置定时器，当鼠标离开窗口3秒后关闭窗口
    //QTimer::singleShot(3000,this,&VolumePopup::close);

/////////////////////////////////////////////////////////////////////////
}

void VolumePopup::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    this->close();
}

// void VolumePopup::close()
// {
//     // 关闭窗口的逻辑
//     this->close(); // 调用父类的 close 方法
// }
