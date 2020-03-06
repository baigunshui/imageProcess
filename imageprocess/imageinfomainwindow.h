#ifndef IMAGEINFOMAINWINDOW_H
#define IMAGEINFOMAINWINDOW_H

#include <QMainWindow>
#include <iostream>
//#include <windows.h>
#include <QMessageBox>
#pragma warning(disable : 4996)
using namespace std;

namespace Ui {
class imageInfoMainwindow;
}

class imageInfoMainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit imageInfoMainwindow(QWidget *parent = nullptr);
    ~imageInfoMainwindow();
//    bool readBmp(char *bmpName);
//    bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable);
//    void doIt();
private:
    Ui::imageInfoMainwindow *ui;
//public:
//    int bmpWidth;//图像的宽
//    int bmpHeight;//图像的高
//    RGBQUAD *pColorTable;//颜色表指针

//    int biBitCount;//图像类型，每像素位数
};

#endif // IMAGEINFOMAINWINDOW_H
