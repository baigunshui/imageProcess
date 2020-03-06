#include "morphingselect.h"
#include "morpher.h"
#include "ui_morphingselect.h"

#include<QDebug>

MorphingSelect::MorphingSelect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MorphingSelect)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,1);
    qDebug()<<"构造了MorphingSelect窗口";
}

MorphingSelect::~MorphingSelect()
{
    delete ui;
}

void MorphingSelect::on_backButton_clicked()
{
    emit sendsignal();
    this->close();
}

void MorphingSelect::on_sureButton_clicked()
{
    Morpher morpher;
    morpher.morphingRun(getCurrentDirPath_1(),getCurrentDirPath_2());
    qDebug()<<getCurrentDirPath_1()<<endl<<getCurrentDirPath_2()<<endl;
}

void MorphingSelect::on_pushButton_1_clicked()
{
    ui->label_1->clear();
    //打开图片操作
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    if(fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this,"警告","打开图片失败!");
        return;
    }
    else
    {
        QImage img(fileName);
        setCurrentDirPath_1(fileName);
        ui->lineEdit_1->setText(fileName);
        img=img.scaled(ui->label_1->width(),ui->label_1->height(),Qt::KeepAspectRatio);//Qt::KeepAspectRatio自适应大小，不变形
        ui->label_1->setPixmap(QPixmap::fromImage(img));
        if(img.isNull())
        {
            QMessageBox::information(this,"信息","打开文件失败");
        }
        else
        {
            //               globalMark=1;//存储标记，用于判断是否有文件
            //                globalImg=img;
        }
    }
}

void MorphingSelect::on_pushButton_2_clicked()
{
    ui->label_2->clear();
    //打开图片操作
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    if(fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this,"警告","打开图片失败!");
        return;
    }
    else
    {
        QImage img(fileName);
        setCurrentDirPath_2(fileName);
        ui->lineEdit_2->setText(fileName);
        img=img.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio);//Qt::KeepAspectRatio自适应大小，不变形
        ui->label_2->setPixmap(QPixmap::fromImage(img));
        if(img.isNull())
        {
            QMessageBox::information(this,"信息","打开文件失败");
        }
        else
        {
            //                globalMark=1;//存储标记，用于判断是否有文件
            //                globalImg=img;
        }
    }
}

QString MorphingSelect::getCurrentDirPath_1() const
{
    return currentDirPath_1;
}

void MorphingSelect::setCurrentDirPath_1(const QString &value)
{
    currentDirPath_1 = value;
}

QString MorphingSelect::getCurrentDirPath_2() const
{
    return currentDirPath_2;
}

void MorphingSelect::setCurrentDirPath_2(const QString &value)
{
    currentDirPath_2 = value;
}
