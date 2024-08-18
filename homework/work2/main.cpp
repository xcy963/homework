#include <opencv2/core/hal/interface.h>

#include <fstream>
#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "example.h"

int point_x[5] = {90, 152, 561, 326, 422};
int point_y[5] = {25, 96, 36, 514, 46};
int i = 0;
int main() {
    cv::Mat image = cv::imread("../picture/dog.jpg");
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // 访问以下坐标点的像素值
    // cv::Point2i point1(90, 25);
    // cv::Point2i point2(152, 96);
    // cv::Point2i point3(561, 36);
    // cv::Point2i point4(326, 514);
    // cv::Point2i point5(422, 46);
    std::ofstream outputFile("output.txt");
    outputFile << "原始图像像素值 (BGR格式):\n";
    i = 0;
    while (i < 5) {
        cv::Vec3b pixel = image.at<cv::Vec3b>(point_x[i], point_y[i]);
        outputFile << "Point (" << point_x[i] << ", " << point_y[i] << "): "
                   << "B: " << static_cast<int>(pixel[0]) << " "
                   << "G: " << static_cast<int>(pixel[1]) << " "
                   << "R: " << static_cast<int>(pixel[2]) << "\n";
        i++;
    }
    outputFile << "\n灰度图像像素值 (int格式):\n";
    i = 0;
    while (i < 5) {
        int pixel = gray.at<uchar>(point_x[i], point_y[i]);
        outputFile << "Point (" << point_x[i] << ", " << point_y[i] << "): "
                   << "Value: " << pixel << "\n";
        i++;
    }
    cv::namedWindow("演示输出图像", cv::WINDOW_NORMAL);
    cv::imshow("演示输出图像", image);
    cv::imshow("灰白图像", gray);
    // 如果不加waitkey,显示窗口一闪而过就结束了
    cv::waitKey(0);
    return 0;
}
