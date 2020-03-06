#include "mainwindow.h"
#include "morphingselect.h"
#include "cannymianwindow.h"
#include "ui_mainwindow.h"
#include "imageinfomainwindow.h"
#include "capturescreen.h"
#include "templatematch.h"


MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent, flags),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);

    currentDirPath = "";
    numofPic = 0;

    ///文件浏览器槽函数
    connect(ui->lineEdit_currentPath,SIGNAL(returnPressed()),this,SLOT(showCurrentDirFiles()));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(showNextDirFiles(QListWidgetItem*)));

    //connect(ui->showButton,SIGNAL(clicked()),this,SLOT(on_showButton_clicked()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(playCurrentItem(QListWidgetItem*)));
    connect(ui->cannyButton,SIGNAL(clicked()),this,SLOT(sendToChild()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QIcon * MainWindow::getItemPropertyIcon(int iType)
{
    QDir dir;

    QString path = dir.currentPath();
    switch(iType)
    {
    case 1:
        return new QIcon(path+"/dir.png");
        break;
    case 2:
        return new QIcon(path+"/file.png");
        break;
    }
    return NULL;
}


void MainWindow::showFileInfoList(QFileInfoList pInfoList)
{
    numofPic = 0;
    ui->listWidget->clear();
    for(int i=0; i<pInfoList.size(); i++)
    {
        QFileInfo tmpInfo = pInfoList.at(i);

        QString pFileName = tmpInfo.fileName();

        QListWidgetItem *tmpItem = new QListWidgetItem(pFileName);
        if(tmpInfo.isDir())
            tmpItem->setIcon(*getItemPropertyIcon(1));
        else {
            tmpItem->setIcon(*getItemPropertyIcon(2));
            ///获取文件后缀名
            QString suffix = tmpInfo.suffix();
            ///只选取*.jpg,*.png格式文件
            if(suffix.indexOf("jpg")<0 && suffix.indexOf("png")<0)
                continue;
            else
                numofPic++;
        }
        ui->listWidget->addItem(tmpItem);
    }
}

void MainWindow::playCurrentItem(QListWidgetItem* item)
{
    QString strName = item->text();
    if(strName.indexOf("jpg")>=0 || strName.indexOf("pnd")>=0)
    {
        ///获取当前目录图片的绝对路径
        QPixmap pic(currentDirPath+"/"+strName);
        setAbsolutePath(currentDirPath+"/"+strName);
        qDebug()<<getAbsolutePath();
        ui->Label->setScaledContents(true);
        ui->Label->setPixmap(pic);
    }
}



void MainWindow::showNextDirFiles(QListWidgetItem *item)
{
    //获取鼠标双击的文件名字
    QString strName = item->text();
    QDir dir;

    //设置路径为当前目录路径
    dir.setPath(ui->lineEdit_currentPath->text());
    dir.cd(strName);
    ui->lineEdit_currentPath->setText(dir.absolutePath());
    setCurrentDirPath(dir.absolutePath());
    qDebug()<<getCurrentDirPath();
    showCurrentDirFiles();

}

QString MainWindow::getCurrentDirPath() const
{
    return currentDirPath;
}

void MainWindow::setCurrentDirPath(const QString &value)
{
    currentDirPath = value;
}

void MainWindow::showPicture(int num)
{
    QListWidgetItem* item = ui->listWidget->item(num);

    QString strName = item->text();
    ///获取当前目录图片的绝对路径
    QPixmap pic(getCurrentDirPath()+"/"+strName);
    QImage* img=new QImage;
    if(! ( img->load(strName) ) ) //加载图像
    {
        QMessageBox::information(this,
                     tr("打开图像失败"),
                     tr("打开图像失败!"));
        delete img;
        return;
    }
    ui->Label->setPixmap(QPixmap::fromImage(*img));

}

void MainWindow::reshow()
{
    this->show();
}

void MainWindow::sendToChild()
{

    emit infoSend(getAbsolutePath());
}

void MainWindow::on_showButton_clicked()
{
//    imageInfoMainwindow imageInfo;
//    imageInfo.doIt();
}

void MainWindow::showCurrentDirFiles()
{
    //获取当前输入的目录
    QDir currentDir(ui->lineEdit_currentPath->text());
    QStringList filelist;
    filelist<<"*";
    QFileInfoList infoList = currentDir.entryInfoList(filelist,QDir::AllEntries,QDir::DirsFirst);
    //在QListWidget里显示文件列表
    this->showFileInfoList(infoList);
}

void MainWindow::on_faceDetection_clicked()
{
    CascadeClassifier cascade;
    //如果要识别人体的其它部位，只需将上面的haarcascade_frontalface_alt2.xml分类器替换即可。
    cascade.load("F:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml");
    Mat srcImg, dstImg, grayImg;

    //2.读图片

    srcImg = imread(getAbsolutePath().toStdString());
    //尺寸调整
    cv::resize(srcImg, srcImg, Size(srcImg.cols, srcImg.rows), 0, 0, INTER_LINEAR); //用线性插值
    dstImg = srcImg.clone();
    //waitKey(0);
    grayImg.create(srcImg.size(), srcImg.type());
    cvtColor(srcImg, grayImg, CV_BGR2GRAY);//生成灰度图，提高检测效率

    //定义7种颜色，用于标记人脸
    Scalar colors[] =
    {
        CV_RGB(255,0,0)

    };
    // 3.检测
    vector<Rect> rect;
    cascade.detectMultiScale(grayImg, rect, 1.1, 3, 0);//分类器对象调用

    qDebug()<<rect.size();

    //4.标记--在脸部画圆
    for (int i = 0; i < rect.size(); i++)
    {
        Point center;
        int radius;
        center.x = cvRound((rect[i].x + rect[i].width * 0.5));
        center.y = cvRound((rect[i].y + rect[i].height * 0.5));
        radius = cvRound((rect[i].width + rect[i].height) *0.25);
        circle(dstImg, center, radius, colors[0], 2);
    }
    //5.显示
    imwrite("F:\\Qt\\project\\pictures\\faceDetection.jpg",dstImg);
    QImage* img=new QImage;
    img->load("F:\\Qt\\project\\pictures\\faceDetection.jpg");
    ui->Label->clear();
    ui->Label->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::on_cannyButton_clicked()
{
    this->hide();
    CannyMianWindow *cannyWindow = new CannyMianWindow(this);

    connect(cannyWindow, SIGNAL(sendsignal()),this,SLOT(reshow()));
    connect(this, SIGNAL(infoSend(const QString &)),cannyWindow,SLOT(recvData(const QString &)));
    cannyWindow->show();
}

void MainWindow::on_morphingButton_clicked()
{
    this->hide();
    MorphingSelect *morphingMainWindow = new MorphingSelect(this);

    connect(morphingMainWindow, SIGNAL(sendsignal()),this,SLOT(reshow()));
    morphingMainWindow->show();
}

QString MainWindow::getAbsolutePath() const
{
    return absolutePath;
}

void MainWindow::setAbsolutePath(const QString &value)
{
    absolutePath = value;
}

void MainWindow::onCatureImage()
{
    // 点击截图按钮开始截图;
    CaptureScreen* captureHelper = new CaptureScreen();
    connect(captureHelper, SIGNAL(signalCompleteCature(QPixmap)), this, SLOT(onCompleteCature(QPixmap)));
    captureHelper->show();

}

void MainWindow::onCompleteCature(QPixmap captureImage)
{
    ui->Label->setPixmap(captureImage);
    captureImage.save("F:/Qt/project/pictures/cature.jpg");
}

void MainWindow::on_templateButton_clicked()
{
    TemplateMatch temp;
    temp.run();
    QImage* img=new QImage;
    img->load("F:\\Qt\\project\\pictures\\result.jpg");
    ui->Label->clear();
    ui->Label->setPixmap(QPixmap::fromImage(*img));
}

void MainWindow::on_pushButton_clicked()
{
    onCatureImage();
}
