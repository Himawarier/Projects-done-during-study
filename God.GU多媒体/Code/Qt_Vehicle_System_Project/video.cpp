#include "video.h"
#include "ui_video.h"



video::video(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::video)
{
    ui->setupUi(this);

    // 创建播放器对象和音量输出对象
    videoPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    // 创建视频显示窗口
    videoWidget = new QVideoWidget(this);
    // 设置视频窗口的大小
    videoWidget->resize(this->width()*2/3,this->height()*2/3);
    //移动位置
    videoWidget->move((this->width()-videoWidget->width())/2,(this->height()-videoWidget->height())/5);

    //设置视频的输出对象
    videoPlayer->setVideoOutput(videoWidget);

    videoPlayer->setAudioOutput(audioOutput); // 设置音频输出
    audioOutput->setVolume(1); //设置满音量



    //实例化一个widget
    popupWidget = new QWidget(ui->widget);
    popupWidget->resize(10,100);
    popupWidget->setStyleSheet("QWidget { background-color: rgba(255, 255, 255, 50); border: none; }");


    // 创建一个垂直布局
    QVBoxLayout *layout = new QVBoxLayout(popupWidget);

    // 创建一个垂直方向的音量滑块
    volumeSlider = new QSlider(popupWidget);
    volumeSlider->setRange(0,100);      // 设置音量滑块的范围为0到100
    volumeSlider->setValue(100); // 初始音量


    layout->addWidget(volumeSlider);     // 将音量滑块添加到布局中
    layout->setContentsMargins(0,0,0,0);   // 移除布局的边距

    // 连接 slider 的信号
    connect(volumeSlider, &QSlider::valueChanged, this, &video::onSliderValueChanged);
    //隐藏popupWidget
    popupWidget->hide();

    // 安装事件过滤器到
    ui->volumeBtn->installEventFilter(this);
    popupWidget->installEventFilter(this);
    videoWidget->installEventFilter(this);
}

video::~video()
{
    delete ui;
}

void video::on_returnBtn_clicked()
{
    this->close();
    delete this;
}

//打开文件
void video::on_openBtn_clicked()
{
    // 获取桌面路径
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    //获取打开文件
    fileName = QFileDialog::getOpenFileName(this,"选择要播放的文件",
                                            QString("%1").arg(desktopPath),
                                            "MP4(*.mp4);;"
                                            "MP3(*.mp3);;"
                                            "FLAC(*.flac)");
}

//开始播放视频
void video::on_playBtn_clicked()
{
    if(fileName.isEmpty())
    {
        //警告
        QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有选择视频呢！\n🤣👉🤡");
        return ;
    }
    switch (videoPlayer->playbackState()) {
    case QMediaPlayer::StoppedState:  //当前没有播放内容时
        videoPlayer->setSource(QUrl::fromUserInput(fileName));          // 设置视频文件
        videoPlayer->play();            // 开始播放视频
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause)); //设置播放图标为暂停图标
        break;

    case QMediaPlayer::PlayingState:
        videoPlayer->pause();           // 如果视频正在播放，则暂停
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart)); //设置播放图标为开始图标
        break;

    case QMediaPlayer::PausedState:
        videoPlayer->play();
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));//设置播放图标为暂停图标
    default:
        break;
    }

}

//快进
void video::on_forwordBtn_clicked()
{
    if(fileName.isEmpty())
    {
        //警告
        QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有选择视频呢！\n🤣👉🤡");
        return ;
    }
    //每次快进5秒
    qint64 currentTime = videoPlayer->position();   // 获取当前播放位置
    qint64 newTime =  currentTime+5000;   // 计算新的播放位置
    videoPlayer->setPosition(newTime); // 跳转到新的播放位置
}

//快退
void video::on_backwordBtn_clicked()
{
    if(fileName.isEmpty())
    {
        //警告
        QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有选择视频呢！\n🤣👉🤡");
        return ;
    }
    //每次快退5秒
    qint64 currentTime = videoPlayer->position();
    qint64 newTime = currentTime-5000;
    if(newTime<0)
    {
        newTime = 0;
    }
    videoPlayer->setPosition(newTime);
}

//点击静音
void video::on_volumeBtn_clicked()
{

    if(volumeSlider->value() != 0)
    {
        volumFlage = volumeSlider->value();
        volumeSlider->setValue(0);
    }
    else
    {
        volumeSlider->setValue(volumFlage);
    }
}

//改变音量大小
void video::onSliderValueChanged()
{
    int value = volumeSlider->value();
    audioOutput->setVolume(value/100.f);
    if(value >= 66)
    {
        ui->volumeBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeHigh));
    }
    else if(value >= 33 && value <= 66)
    {
        ui->volumeBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeMedium));
    }
    else if(value > 0 && value <= 33)
    {
        ui->volumeBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeLow));
    }
    else if(value == 0)
    {
        ui->volumeBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::AudioVolumeMuted));
    }
}
 //隐藏窗口
void video::hiddenWidget()
{
    if(flage != 1)
    {
        popupWidget->hide();
        flage = 0;
    }
}

//鼠标事件
bool video::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == ui->volumeBtn  && event->type() == QEvent::Enter) {
        // 显示 popup
        // 注意：这里需要手动计算popup的位置
        int x = ui->volumeBtn->x(); //获取音量键按钮的x坐标
        int y = ui->controlListWidget->y(); //获取音量键的父窗口controlListWidge的y坐标
        int xw = ui->volumeBtn->width();
        int h = popupWidget->height(); //获取滑动条的高
        popupWidget->move(x+xw/2,y-h);
        popupWidget->show();
        return true;
    }
    else if (obj == ui->volumeBtn && event->type() == QEvent::Leave) {
        // 延迟隐藏 popup
        QTimer::singleShot(3000,this,&video::hiddenWidget);
        return true;
    }
    else if(obj == popupWidget && event->type() == QEvent::Leave) {
        // 离开滚动条隐藏 popup
        popupWidget->hide();
        flage = 0;
        return true;
    }
    else if(obj == popupWidget && event->type() == QEvent::Enter)
    {
        flage = 1;
    }
    else if(obj == videoWidget && event->type() ==QEvent::MouseButtonDblClick)
    {
        // if (videoWidget->isFullScreen()) {
        //     videoWidget->setWindowFlags (Qt::SubWindow);  //降低为子窗口showNormal只能还原子窗口
        //     videoWidget->showNormal();                   //取消全局显示
        //     videoWidget->resize(this->width()*2/3,this->height()*2/3); //设置大小为原来的大小
        // }
        // else
        // {
        //     videoWidget->setWindowFlags (Qt::Window);  //提升为顶层窗口 ，showFullScreen（）只能显示顶层窗口
        //     videoWidget->showFullScreen ();              //全局显示
        // }

        if(videoWidget->isFullScreen())
        {
            videoWidget->setFullScreen(false);                          //QVideoWidget提供的取消全屏显示
            videoWidget->resize(this->width()*2/3,this->height()*2/3);  //设置大小为原来的大小
            //移动位置
            videoWidget->move((this->width()-videoWidget->width())/2,(this->height()-videoWidget->height())/5);
        }
        else
        {
            videoWidget->setFullScreen(true);   //QVideoWidget提供的全屏显示
        }

    }
    return false;

}

//点击放大按钮设置为全屏
void video::on_zoomBtn_clicked()
{
    if(videoWidget->width()==ui->widget->width())
    {
        ui->zoomBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ViewFullscreen));
        //videoWidget->resize(ui->videoLabel->size());
        videoWidget->resize(this->width()*2/3,this->height()*2/3);
        //移动位置
        videoWidget->move((this->width()-videoWidget->width())/2,(this->height()-videoWidget->height())/5);
    }
    else
    {
        ui->zoomBtn->setIcon(QIcon(":/UI//Img/zoomBtn.png"));
        videoWidget->resize(ui->widget->width(),ui->widget->height() - ui->controlListWidget->height());
        videoWidget->move(0,0);
    }

}

