#include "baidumap.h"
#include "ui_baidumap.h"

BaiduMap::BaiduMap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaiduMap)
{
    ui->setupUi(this);

    ui->mapSizeBar->setValue(zoom);
    showMap();
    connect(this,&BaiduMap::emitXY,this,&BaiduMap::showMap);
}

BaiduMap::~BaiduMap()
{
    delete ui;    
}

void BaiduMap::mousePressEvent(QMouseEvent *ev)
{
    QPointF pos = ev->position();
    qDebug()<<__LINE__;
    px= pos.x();
    py= pos.y();
}

void BaiduMap::mouseReleaseEvent(QMouseEvent *ev)
{
    QPointF pos = ev->position();
    qDebug()<<__LINE__;
    lx= pos.x();
    ly= pos.y();

    lng -= (lx-px)*0.0000003*(18-zoom)*(18-zoom)*(18-zoom)*(18-zoom);

    lat += (ly-py)*0.0000003*(18-zoom)*(18-zoom)*(18-zoom)*(18-zoom);
    emit this->emitXY();
}

void BaiduMap::getImg(QNetworkReply *reply)
{
    QByteArray img = reply->readAll();
    if(img.isEmpty())
        return ;
    QPixmap map;

    if(map.loadFromData(img))
    {
        map.scaled(ui->mapLabel->size());
        ui->mapLabel->setPixmap(map);
    }
    else
    {
        qDebug()<<"失败";
    }
}

void BaiduMap::showMap()
{
    //地图获取请求
    netManger = new QNetworkAccessManager();

    QUrl url(GdUrl.arg(key).arg(lng).arg(lat).arg(zoom));

    QNetworkRequest reques(url);

    netManger->get(reques);

    connect(netManger,&QNetworkAccessManager::finished,this,&BaiduMap::getImg);
}

void BaiduMap::on_returnBtn_clicked()
{
    this->close();
    delete this;
}


void BaiduMap::on_mapSizeBar_valueChanged(int value)
{
    zoom = value;
    emit emitXY();
}

