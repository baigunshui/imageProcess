#include "templatematch.h"

TemplateMatch::TemplateMatch()
{

}

TemplateMatch::~TemplateMatch()
{

}

void TemplateMatch::MatchingMethod(int, void *)
{

     /// 创建输出结果的矩阵
     int result_cols =  mImg2.cols - templ.cols + 1;     //计算用于储存匹配结果的输出图像矩阵的大小
     int result_rows = mImg2.rows - templ.rows + 1;

     result.create( result_cols, result_rows, CV_32FC1 );//被创建矩阵的列数，行数，以CV_32FC1形式储存。

     /// 进行匹配和标准化
     matchTemplate( mImg2, templ, result, CV_TM_SQDIFF_NORMED); //待匹配图像，模版图像，输出结果图像，匹配方法（由滑块数值给定。）

     //输入数组，输出数组，range normalize的最小值，range normalize的最大值，归一化类型，当type为负数的时候输出的type和输入的type相同。
     normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

     /// 通过函数 minMaxLoc 定位最匹配的位置
     double minVal=-1;
     double maxVal;
     Point minLoc;
     Point maxLoc;
     Point matchLoc;

     minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );//用于检测矩阵中最大值和最小值的位置


     matchLoc = minLoc;
     //将得到的结果用矩形框起来
     rectangle( mImg2, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar(0,0,255), 2, 8, 0 );

     imwrite("F:\\Qt\\project\\pictures\\result.jpg",mImg2);
     return;
}

void TemplateMatch::run()
{
    mImg2 = imread("F:\\Qt\\project\\pictures\\1.jpg");//载入待匹配图像
    templ = imread("F:\\Qt\\project\\pictures\\cature.jpg");//载入模版图像

    MatchingMethod( 0,0 );//初始化显示


}
