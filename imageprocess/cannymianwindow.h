#ifndef CANNYMIANWINDOW_H
#define CANNYMIANWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QMessageBox>

using namespace cv;
using namespace std;
#define PI 3.14159265358979323846
#define IS_SAVE_IMAGE true //是否保存图像
#define IS_SHOW_MID_IMAGE true //是否显示处理过程


namespace Ui {
class CannyMianWindow;
}

class CannyMianWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CannyMianWindow(QWidget *parent = nullptr);
    ~CannyMianWindow();

    void saveImage(const string &winname, Mat image, bool isSave);
    void showImage(int num, const string &Path);
    Mat createGaussianKernel2D(int ksize,float sigma);
    void gaussianFilter(const Mat &src,Mat &dst, int ksize = 3, float sigma = 1.0);
    void gCanny(const Mat &_src, Mat &_dst,double low_thresh, double high_thresh, int sobel_size = 3);
    void hough(Mat srcImage, Mat midImage, Mat dstImage);
    void runCanny();

    QString getPath() const;
    void setPath(const QString &value);

private slots:
    void on_backButton_clicked();
    void recvData(const QString &);

signals:
    void sendsignal();

private:
    Ui::CannyMianWindow *ui;
    QString Path;
};

#endif // CANNYMIANWINDOW_H
