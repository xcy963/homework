#include <opencv2/core/hal/interface.h>

#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "example.h"

int main() {
    cv::Mat image = cv::imread("../picture/apple.jpeg");

    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    cv::Scalar lowerRed1(0, 100, 100);
    cv::Scalar upperRed1(10, 255, 255);
    cv::Scalar lowerRed2(160, 100, 100);
    cv::Scalar upperRed2(180, 255, 255);

    cv::Mat mask1, mask2, redMask;
    cv::inRange(hsvImage, lowerRed1, upperRed1, mask1);
    cv::inRange(hsvImage, lowerRed2, upperRed2, mask2);

    redMask = mask1 | mask2;

    cv::Mat morphKernel =
        cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
    cv::morphologyEx(redMask, redMask, cv::MORPH_CLOSE, morphKernel);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(redMask, contours, hierarchy, cv::RETR_TREE,
                     cv::CHAIN_APPROX_SIMPLE);

    cv::Scalar color(255, 0, 0);  // 框框的颜色
    int thickness = 2;
    for (const auto& contour : contours) {
        if (contour.size() > 0) {
            cv::Point2f center;
            float radius;
            cv::minEnclosingCircle(contour, center, radius);

            // 绘制圆形
            cv::circle(image, center, static_cast<int>(radius), color,
                       thickness);
        }
    }

    // 显示结果
    cv::imshow("演示输出图像", image);
    // 如果不加waitkey,显示窗口一闪而过就结束了
    cv::waitKey(0);
}
