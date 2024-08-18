#include <iostream>
#include <opencv2/opencv.hpp>  // OpenCV 主头文件
using namespace std;

int main() {
    // 读取图像
    cv::Mat img = cv::imread("image.jpg");

    // 检查图像是否成功加载
    if (img.empty()) {
        std::cout << "无法打开或找到图像文件" << std::endl;
        return -1;
    }

    // 将图像转换为灰度图像
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // 显示原始图像和灰度图像
    cv::imshow("原始图像", img);
    cv::imshow("灰度图像", gray);

    // 等待按键输入
    cv::waitKey(0);

    // 销毁所有窗口
    cv::destroyAllWindows();

    return 0;
}