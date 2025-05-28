#ifndef BAIDUMAP_H
#define BAIDUMAP_H

#include <QWidget>

#include <QMouseEvent>
#include <QNetWorkAccessManager>
#include <QNetworkReply>
#include <QPointF>

namespace Ui {
class BaiduMap;
}

class BaiduMap : public QWidget
{
    Q_OBJECT

public:
    explicit BaiduMap(QWidget *parent = nullptr);
    ~BaiduMap();


private:
    Ui::BaiduMap *ui;
    QNetworkAccessManager *netManger;

    QString GdUrl=QString("https://api.map.baidu.com/staticimage/v2?ak=%1&center=%2,%3&width=400&height=240&zoom=%4&scale=2");
    QString key = QString("J6Xjtyqd9CrpHvzRVrCSUCp2mfaSkkkN");
    int zoom = 10;
    double lng=104.679127,lat=31.467673;

    double px=0,py=0,lx=0,ly=0;


    //鼠标按下事件  这个virtual写不写都可以，这是虚关键词 表示虚函数
    virtual void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent *ev);


signals:
    void emitXY();


private slots:
    void getImg(QNetworkReply *reply);
    void showMap();
    void on_returnBtn_clicked();
    void on_mapSizeBar_valueChanged(int value);
};

#endif // BAIDUMAP_H
