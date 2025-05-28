#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Man! What can i say? 曼波~");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_mapBtn_clicked()
{
    baiduMap = new BaiduMap(this);
    baiduMap->show();
}


void Widget::on_videoBtn_clicked()
{
    Video = new video(this);
    Video->show();
}


void Widget::on_musicBtn_clicked()
{
    music = new Music(this);
    music->show();
}

