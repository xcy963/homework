#include <Eigen/Dense>
#include <cmath>
#include <iostream>

int main() {
    double thetaY = M_PI / 3;  // 60 degrees in radians

    // 初始点P在A坐标系下的坐标
    Eigen::Vector4d P(1, 0, 0, 1);  // 齐次坐标
    Eigen::Matrix4d Ry;
    Ry << std::cos(thetaY), 0, -std::sin(thetaY), 0, 0, 1, 0, 0,
        std::sin(thetaY), 0, std::cos(thetaY), 0, 0, 0, 0, 1;
    Eigen::Vector4d P1;
    P1 = Ry * P;  // 第一次的转60度
    // std::cout << P1;
    Eigen::Vector4d d(-0.75, 0.5, std::sin(thetaY) / 2, 0);  // 斜面的方向向量
    P1 = P1 + d * 1;
    std::cout << P1;
    return 0;
}
