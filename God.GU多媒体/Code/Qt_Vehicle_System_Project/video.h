#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QAudioOutput>
#include <QSlider>
#include <QTimer>
#include <QStandardPaths>
#include <QMessageBox>
#include <QPushButton>


namespace Ui {
class video;
}

class video : public QWidget
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

private slots:
    void on_returnBtn_clicked();

    void on_openBtn_clicked();

    void on_playBtn_clicked();

    void on_forwordBtn_clicked();

    void on_backwordBtn_clicked();

    void on_volumeBtn_clicked();


    void onSliderValueChanged();

    void hiddenWidget();


    void on_zoomBtn_clicked();


protected:
    //重写鼠标事件
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::video *ui;

    QMediaPlayer *videoPlayer;
    QVideoWidget *videoWidget;
    QAudioOutput *audioOutput;
    QString fileName;

    QWidget *popupWidget;
    // 存储音量滑块的指针
    QSlider *volumeSlider;

    int flage = 0;
    int volumFlage;//记录声音大小

};

#endif // VIDEO_H
