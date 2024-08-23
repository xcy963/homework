#include <Eigen/Dense>
#include <cmath>
#include <iostream>

int main() {
    // 旋转角度
    double thetaX = M_PI / 3;  // 60 degrees in radians
    double thetaY = M_PI / 6;  // 30 degrees in radians

    Eigen::Vector3d P(0, 0, 0);

    Eigen::Vector3d P1(1, 1, 2);

    Eigen::Matrix3d Rx;
    Rx << 1, 0, 0, 0, std::cos(thetaX), -std::sin(thetaX), 0, std::sin(thetaX),
        std::cos(thetaX);

    Eigen::Vector3d P_prime = Rx * P1;

    Eigen::Matrix3d Ry;
    Ry << std::cos(thetaY), 0, std::sin(thetaY), 0, 1, 0, -std::sin(thetaY), 0,
        std::cos(thetaY);

    Eigen::Vector3d P_prime_in_B = Ry * P_prime;

    std::cout << "P' 在B坐标系里面的坐标是:\n" << P_prime_in_B << std::endl;

    // 下面用齐次矩阵来写
    Eigen::Matrix4d Rx_1;
    Rx_1 << 1, 0, 0, 0, 0, std::cos(thetaX), -std::sin(thetaX), 0, 0,
        std::sin(thetaX), std::cos(thetaX), 0, 0, 0, 0, 1;

    Eigen::Matrix4d Ry_1;
    Ry_1 << std::cos(thetaY), 0, std::sin(thetaY), 0, 0, 1, 0, 0,
        -std::sin(thetaY), 0, std::cos(thetaY), 0, 0, 0, 0, 1;

    Eigen::Matrix4d Rt_1;
    Rt_1 << 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 1;

    std::cout << "T是" << Ry_1 * Rx_1 * Rt_1;
    return 0;
}
