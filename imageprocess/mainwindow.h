#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QListWidgetItem>
#include <QMessageBox>



///字符编码
#include <QTextCodec>
///图标
#include <QIcon>
///目录
#include <QDir>
///定时器
#include <QTimer>
///图片
#include <QPixmap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,Qt::WindowFlags flags = 0);
    ~MainWindow();
    QString getCurrentDirPath() const;
    void setCurrentDirPath(const QString &value);
    void showFileInfoList(QFileInfoList pInfoList);
    QIcon *getItemPropertyIcon(int iType);
    void showPicture(int num);

    QString getAbsolutePath() const;
    void setAbsolutePath(const QString &value);
    void onCatureImage();


private slots:
    void reshow();
    void sendToChild();
    void on_showButton_clicked();
    void onCompleteCature(QPixmap captureImage);
    ///显示当前目录下的文件夹和文件
    void showCurrentDirFiles();
    ///鼠标点击列表时显示
    void playCurrentItem(QListWidgetItem* item);

    ///显示鼠标双击的列表里的文件夹下的文件
    void showNextDirFiles(QListWidgetItem *item);
    void on_faceDetection_clicked();

    void on_cannyButton_clicked();

    void on_morphingButton_clicked();

    void on_templateButton_clicked();

    void on_pushButton_clicked();

signals:
    void infoSend(const QString &);

private:
    Ui::MainWindow *ui;
    QString currentDirPath;
    QString absolutePath;
    int numofPic;

    QPixmap m_pixmap;
    float scalling;
    bool isLoaded;
    bool isIntialised;
    bool isCropping;
};

#endif // MAINWINDOW_H
