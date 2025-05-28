#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QTimer>
#include <QMessageBox>
#include <QMovie>
  #include <QRandomGenerator>
#include <QStandardPaths>

namespace Ui {
class Music;
}

class Music : public QWidget
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

    void localSongList();

    void hiddenWidget();


    void lyricFileAnanly(QString path);

private slots:

    void on_openBtn_clicked();

    void on_playBtn_clicked();

    void on_returnBtn_clicked();

    void on_songListWidget_itemClicked(QListWidgetItem *item);

    void updateProgressBar(qint64 position);

    void on_musicSlider_sliderMoved(int position);

    void on_musicSlider_valueChanged(int value);

    void onSliderValueChanged();


    void on_volumeBtn_clicked();

    void on_nextBtn_clicked();

    void on_lastBtn_clicked();

protected:
    //重写鼠标事件
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::Music *ui;

    QMediaPlayer *musicPlayer;
    QAudioOutput *audioOutput;

    QString fileName;

    QListWidgetItem *currentItem;

    QWidget *popupWidget;
    // 存储音量滑块的指针
    QSlider *volumeSlider;

    int flage = 0;
    int volumFlage;//记录声音大小


    //歌词结构体
    typedef struct one_lyric_st
    {
        int flag;            //记录是否有歌词
        int pos;            //歌词位置
        qint64 time;        //歌词时间ms
        QString lyricStr;   //歌词内容
        QString timeStr;    //时间字符串，后期可以显示滑轮时对应的时间提示
    }one_lyric;
    //歌词结构体数组 假设一首歌300行
    one_lyric lyrics[300];
    int curpos,lyrics_size;    // 当前播放位置和歌词总数


};

#endif // MUSIC_H
