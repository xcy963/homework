cmake_minimum_required(VERSION 3.10)
project(2024_week2)
# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 OpenCV 包
find_package(OpenCV REQUIRED)

# 打印 OpenCV 版本（可选）
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

# 添加可执行文件
add_executable(trail trail.cpp)

# 链接 OpenCV 库到可执行文件
target_link_libraries(trail ${OpenCV_LIBS})
