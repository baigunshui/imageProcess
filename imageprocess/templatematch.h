#ifndef TEMPLATEMATCH_H
#define TEMPLATEMATCH_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>


using namespace std;
using namespace cv;

class TemplateMatch
{
public:
    TemplateMatch();
    ~TemplateMatch();
    void MatchingMethod( int, void* );
    void run();
public:
    Mat mImg2;
    Mat templ;
    Mat result;
    char* image_window = "Final Image";
    int match_method;//匹配方法索引
    int max_Trackbar = 5;
};

#endif // TEMPLATEMATCH_H
