#include "music.h"
#include "ui_music.h"




Music::Music(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Music)
{
    ui->setupUi(this);

    // 创建播放器对象和音量输出对象
    musicPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    musicPlayer->setAudioOutput(audioOutput); // 设置音频输出
    audioOutput->setVolume(1); //设置满音量

    // 当音频播放位置改变时，更新进度条的当前位置
    connect(musicPlayer, &QMediaPlayer::positionChanged, this, &Music::updateProgressBar);
    connect(musicPlayer, &QMediaPlayer::durationChanged, [=](qint64 duration){
        ui->musicSlider->setRange(0,duration);
    });


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
    connect(volumeSlider, &QSlider::valueChanged, this, &Music::onSliderValueChanged);
    //隐藏popupWidget
    popupWidget->hide();

    // 安装事件过滤器到
    ui->volumeBtn->installEventFilter(this);
    popupWidget->installEventFilter(this);

}

Music::~Music()
{
    delete ui;
}

//退出
void Music::on_returnBtn_clicked()
{
    this->close();
    delete this;
}

//打开文件
void Music::on_openBtn_clicked()
{
    // 获取桌面路径
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    //获取打开文件
    QStringList fileNames = QFileDialog::getOpenFileNames(this,"选择音乐文件",
                                                          QString("%1").arg(desktopPath),
                                                          "OGG(*.ogg);;"
                                                          "FLAC(*.flac);;"
                                                          "MP4(*.mp4);;"
                                                          "MP3(*.mp3)");

    if (!fileNames.isEmpty()) {
        // 遍历所有选中的文件
        foreach (const QString &fileName, fileNames) {
            // 使用 QFileInfo 获取文件名
            QFileInfo fileInfo(fileName);
            QString fileNameOnly = fileInfo.fileName(); // 获取文件名，不包括路径

            // 创建一个新的QListWidgetItem，并设置其文本为文件名
            QListWidgetItem *item = new QListWidgetItem(fileNameOnly);
            // 将文件路径作为项的用户数据存储
            item->setData(Qt::UserRole, fileName);
            // 将项添加到QListWidget
            ui->songListWidget->addItem(item);
        }
    }
}

//播放按钮
void Music::on_playBtn_clicked()
{
    if(fileName.isEmpty())
    {
        if(ui->songListWidget->count() == 0)
        {
            //警告
            QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有添加歌曲呢！\n🤣👉🤡");
            return ;
        }
        QListWidgetItem *nextItem = ui->songListWidget->item(0);
        Music::on_songListWidget_itemClicked(nextItem);
        ui->songListWidget->setCurrentItem(nextItem);
    }
    switch (musicPlayer->playbackState()) {
    case QMediaPlayer::StoppedState:  //当前没有播放内容时
        musicPlayer->setSource(QUrl::fromUserInput(fileName));          // 设置音频文件
        musicPlayer->play();            // 开始播放
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause)); //设置播放图标为暂停图标
        break;

    case QMediaPlayer::PlayingState:
        musicPlayer->pause();           // 如果正在播放，则暂停
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart)); //设置播放图标为开始图标
        break;

    case QMediaPlayer::PausedState:  //如果暂停就开始播放
        musicPlayer->play();
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause));//设置播放图标为暂停图标
    default:
        break;
    }
}

//list表中音乐被点击
void Music::on_songListWidget_itemClicked(QListWidgetItem *item)
{
    currentItem = item;
    fileName.clear();
    //fileName = QString("qrc"+item->data(Qt::UserRole).toString()); //把item的文件路径加上资源文件前缀
    fileName = item->data(Qt::UserRole).toString();

    QFileInfo fileInfo(fileName);
    QString baseName = fileInfo.baseName(); // 获取文件的基本名（不包含扩展名）
    QString directory = fileInfo.absolutePath(); // 获取文件的绝对路径（包含文件夹）
    //qDebug()<<QString("%1/%2.lrc").arg(directory).arg(baseName);
    lyricFileAnanly(QString("%1/%2.lrc").arg(directory).arg(baseName));
    ui->songName->setText(baseName);


    musicPlayer->setSource(QUrl::fromUserInput(fileName));          // 设置音频文件
    musicPlayer->play();            // 开始播放
    ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause)); //设置播放图标为暂停图标
}

//跟新进度条
void Music::updateProgressBar(qint64 position)
{
    ui->musicSlider->setValue(position);
}

//滑动进度条
void Music::on_musicSlider_sliderMoved(int position)
{
    musicPlayer->setPosition(position);
}

//值改变更新时间
void Music::on_musicSlider_valueChanged(int value)
{
    if(value == musicPlayer->duration())
    {
        ui->playBtn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart)); //设置播放图标为开始图标
        ui->timeLabel->setText("00:00");
        ui->musicSlider->setValue(0);
        return ;
    }

    if(value/1000 == lyrics[curpos].time)
    {
        if(lyrics[curpos].flag == false)
        {
            ui->lyric3->setText("💐没有找到歌词文件，请查看文件💕");
            return;
        }
        ui->lyric1->clear();
        ui->lyric2->clear();
        ui->lyric4->clear();
        ui->lyric5->clear();
        if(curpos>=3)
        {
            ui->lyric1->setText(lyrics[curpos-2].lyricStr);
            ui->lyric2->setText(lyrics[curpos-1].lyricStr);
        }

        int rand = QRandomGenerator::global()->bounded(16); //设置随机数
        ui->lyric3->setText(QString(" %1 %2 %3 ").arg(
                // 机选择%1的字符
                QStringList{"💕", "🍁", "🌸","🏵️","🌹","🌺","🌷","🪻","☘️","🪴","🍀","🍂","🍃","🌼", "🌻", "💐"}[rand],
                // %2是歌词字符串
                lyrics[curpos].lyricStr,
                // 机选择%3的字符
                QStringList{"💕", "🍁", "🌸","🏵️","🌹","🌺","🌷","🪻","☘️","🪴","🍀","🍂","🍃","🌼", "🌻", "💐"}[15-rand]));                                           // 机选择%3的字符);


        if(curpos<=lyrics_size-2)
        {
            ui->lyric4->setText(lyrics[curpos+1].lyricStr);
            ui->lyric5->setText(lyrics[curpos+2].lyricStr);
        }

        curpos++;
    }


    qint64 minutes = value / (1000 * 60);             // 走过的毫秒转分钟
    qint64 seconds = (value % (1000 * 60)) / 1000;    // 走过的剩余的毫秒转秒


    // 使用QString的arg()方法来格式化字符串
    // %1是第一个参数（分钟），%2是第二个参数（秒），它们都会被替换为相应的值
    // d是十进制整数，2是宽度，如果数字的位数少于2，则前面会补0（即实现秒数的两位数显示）
    ui->timeLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
}

//音量改变
void Music::onSliderValueChanged()
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

//隐藏音量窗口
void Music::hiddenWidget()
{
    if(flage != 1)
    {
        popupWidget->hide();
        flage = 0;
    }
}

//歌词解析
void Music::lyricFileAnanly(QString path)
{
    // 定义一个位置变量，用于跟踪当前处理的行号
    int pos = 0;


    // 初始化当前播放位置和歌词总数
    this->curpos = 0;
    this->lyrics_size = 0;



    // 使用QFile类打开指定的文件路径，以只读和文本模式
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 如果文件打开失败
        for(int i = 0;i<300;i++)
        {
            this->lyrics[i].pos = 0;
            this->lyrics[i].time=0;
            this->lyrics[i].flag = false;
        }

        return;
    }



    // 逐行读取文件内容，直到文件末尾
    while(file.atEnd()==false)
    {
        // 读取一行文本，包括换行符
        QByteArray lineByte =file.readLine();
        // 移除末尾的换行符'\n'
        lineByte.resize(lineByte.size()-1);
        QString lineStr = lineByte;
        //qDebug()<<lineStr;

        // 跳过前5行
        if(pos>=5)
        {
            // 歌词数量加一
            lyrics_size++;
            // 使用']'字符分割每一行，通常LRC文件中时间戳和歌词之间用这个字符分隔
            QStringList resultList=lineStr.split(']');
            // 每一行分割后有两个部分：时间戳和歌词
            QString timeStr= resultList.at(0);          //时间
            QString lyricStr= resultList.at(1);         //歌词

            // 分割时间戳字符串，按':'分割分钟和秒
            QStringList templist=timeStr.split(':');
            QString min=templist.at(0);                 //分钟
            min=min.split('[').at(1);      //去掉前面的[

            // 提取秒（以及可能的毫秒），先按'.'分割秒和毫秒（如果有）
            QString tempStr=templist.at(1);
            templist=tempStr.split('.');   //按点分割
            QString sec=templist.at(0);                 //秒
            //QString msec = templist.at(1);    //毫秒

            //qDebug()<<pos<<min<<sec;
            this->lyrics[pos-5].pos=pos-5;   //让歌词结构体数组的位置表示第几行歌词
            this->lyrics[pos-5].time=min.toInt()*60+sec.toInt();
            this->lyrics[pos-5].lyricStr=lyricStr;
            this->lyrics[pos-5].timeStr=min+":"+sec;
            this->lyrics[pos-5].flag = true;
            //qDebug()<<"行："<<lyrics[pos-5].pos<<"time："<<lyrics[pos-5].time<<lyrics[pos-5].lyricStr;
        }
        pos++;
    }
    lyrics_size=pos;
    file.close();
}

//鼠标事件
bool Music::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->volumeBtn  && event->type() == QEvent::Enter) {
        // 显示 popup
        // 注意：这里需要手动计算popup的位置
        int x = ui->volumeBtn->x(); //获取音量键按钮的x坐标
        int y = ui->musicControlWidget->y(); //获取音量键的父窗口controlListWidge的y坐标
        int xw = ui->volumeBtn->width(); //获取宽
        int h = popupWidget->height(); //获取滑动条的高
        popupWidget->move(x+xw/2,y-h);
        popupWidget->show();
        return true;
    }
    else if (obj == ui->volumeBtn && event->type() == QEvent::Leave) {
        // 延迟隐藏 popup
        QTimer::singleShot(3000,this,&Music::hiddenWidget);
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
    return false;

}

//点击静音
void Music::on_volumeBtn_clicked()
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



//下一首
void Music::on_nextBtn_clicked()
{
    if(ui->songListWidget->count() == 0)
    {
        //警告
        QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有添加歌曲呢！\n🤣👉🤡");
        return ;
    }
    int currentIndex = ui->songListWidget->row(currentItem);
    int nextIndex = currentIndex + 1;

    // 检查是否有下一个项 ui->songListWidget->count()是当前列表中所有项的总和
    if (nextIndex < ui->songListWidget->count())
    {
        QListWidgetItem *nextItem = ui->songListWidget->item(nextIndex);
        Music::on_songListWidget_itemClicked(nextItem);
        ui->songListWidget->setCurrentItem(nextItem);
    }
    else
    {
        QListWidgetItem *nextItem = ui->songListWidget->item(0);
        Music::on_songListWidget_itemClicked(nextItem);
        ui->songListWidget->setCurrentItem(nextItem);
    }
}

//上一首
void Music::on_lastBtn_clicked()
{
    if(ui->songListWidget->count() == 0)
    {
        //警告
        QMessageBox::warning(this,"警告","\n嗐，你看看，又急！\n你还没有添加歌曲呢！\n🤣👉🤡");
        return ;
    }

    int currentIndex = ui->songListWidget->row(currentItem);
    int nextIndex = currentIndex - 1;

    // 检查是否有上一个项
    if (nextIndex >= 0) {
        QListWidgetItem *nextItem = ui->songListWidget->item(nextIndex);
        Music::on_songListWidget_itemClicked(nextItem);
        ui->songListWidget->setCurrentItem(nextItem);
    }
    else
    {
        QListWidgetItem *nextItem = ui->songListWidget->item(ui->songListWidget->count()-1);
        Music::on_songListWidget_itemClicked(nextItem);
        ui->songListWidget->setCurrentItem(nextItem);
    }
}


// //加载src资源的
// void Music::localSongList()
// {
//     // 创建一个QDir对象，用于表示特定的目录
//     QDir dir(":/Song/Music"); // 设置为你的音乐文件夹路径
//     // 使用QDir的entryInfoList方法获取目录中所有文件的QFileInfo列表
//     // QStringList中包含了通配符模式，这里指定了只查找MP3文件
//     // QDir::Files作为过滤参数，表示只获取文件，不包括目录
//     QFileInfoList fileInfoList = dir.entryInfoList(QStringList() << "*.flac"<<"*.mp4" << "*.mp3" << "*.ogg", QDir::Files);

//     // 遍历QFileInfoList中的每个QFileInfo对象
//     foreach (const QFileInfo &fileInfo, fileInfoList) {
//         // 从QFileInfo对象中获取文件的完整路径
//         QString filePath = fileInfo.absoluteFilePath();
//         // 更新标签文本以显示文件列表
//         // 使用\n来换行，<a href="...">...</a>创建一个可点击的链接
//         // fileInfo.fileName()获取不带路径的文件名

//         // 创建一个新的QListWidgetItem，并设置其文本为文件名
//         QListWidgetItem *item = new QListWidgetItem(fileInfo.fileName());
//         // 将文件路径作为项的用户数据存储
//         item->setData(Qt::UserRole, filePath);
//         // 将项添加到QListWidget
//         ui->songListWidget->addItem(item);
//     }
// }

