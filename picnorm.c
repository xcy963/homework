#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "omp.h"
// #include <iostream>
//  #include <algorithm>  //
//  #include <cmath>
//  #include <iostream>
//  #include <string>
//  #include <thread>
// #include <boost/thread.hpp>

void imageSmoothing(int **img) {
    for (int j = 1; j < 1920; j++) {
        for (int i = 1; i < 1080; i++) {
            img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] +
                         img[i][j + 1]) /
                        4;
            // 取某个像素周围四个点的平均值
        }
    }
}

void imageSmoothing_CPUoptimize(int **img)  // 面向CPU的优化（循环展开）
{
    for (int j = 1; j < 1920 - 1; j++) {         // 保持在有效范围内
        for (int i = 1; i < 1080 - 1; i += 4) {  // 循环展开4次
            // 处理第i, i+1, i+2, i+3行的像素
            img[i][j] = (img[i - 1][j] + img[i + 1][j] + img[i][j - 1] +
                         img[i][j + 1]) /
                        4;
            img[i + 1][j] = (img[i][j - 1] + img[i + 2][j] + img[i][j + 1] +
                             img[i + 1][j]) /
                            4;
            img[i + 2][j] = (img[i + 1][j - 1] + img[i + 3][j] +
                             img[i + 2][j - 1] + img[i + 2][j + 1]) /
                            4;
            img[i + 3][j] = (img[i + 2][j - 1] + img[i + 4][j] +
                             img[i + 3][j - 1] + img[i + 3][j + 1]) /
                            4;
        }
    }
}

void imageSmoothing_CacheOptimize(int **img)  // 面向Cache的优化（分块处理）
{
    // 三级缓存32MB：1080*1920*8=16588800,
    // 16588800/1024/1024=15.82MB，故无需分块
    for (int i = 0; i < 8;
         i++)  // 二级缓存3MB：15.82MB/3MB=5，故将原数据分成8块。
    {
        for (int j = 0; j < 16;
             j++)  // 一级缓存192kb，3MB/192kb=16，故再分成16块
        {
            int L2block = i * 240;  // L2block有1920/8=240行
            int L1block = j * 15;   // L1block有240/16=15行
            for (int colPtr = 1; colPtr <= 15;
                 colPtr++)  // 实时指向每一级的指针
            {
                int nowCol = colPtr + L1block + L2block;  // 当前行的读数
                if (nowCol == 1919) break;
                for (int k = 1; k < 1080; k++)  // 列的读数
                {
                    img[nowCol][k] = (img[nowCol - 1][k] + img[nowCol + 1][k] +
                                      img[nowCol][k - 1] + img[nowCol][k + 1]) /
                                     4;
                }
            }
        }
    }
}

void imageSmoothing_NormalOptimize(int **img)  // 针对复杂运算简化的优化
{
    int divisor = 4;

    // 遍历有效像素区域（避免边界处理）
    for (int j = 1; j < 1920 - 1; j++) {
        for (int i = 1; i < 1080 - 1; i++) {
            // 获取周围四个像素的值
            int top = img[i - 1][j];
            int bottom = img[i + 1][j];
            int left = img[i][j - 1];
            int right = img[i][j + 1];

            // 计算平均值
            img[i][j] = (top + bottom + left + right) / divisor;
        }
    }
}

int main() {
    int **img = (int **)malloc(
        sizeof(int *) *
        1922);  // 在1920*1080的图像边缘增加一圈像素，防止滑窗溢出图像
    srand((int)time(NULL));  // 随机种子
    int number = 0;

    for (int i = 0; i < 1922; i++) {
        img[i] = (int *)malloc(
            sizeof(int) *
            1082);  // 在1920*1080的图像边缘增加一圈像素，防止滑窗溢出图像
        for (int j = 0; j < 1082; j++)  // 为每个图像添加高斯噪声
        {
            number = rand();
            img[i][j] = number;
        }
    }

    clock_t startTimeVal = clock();
    for (int i = 0; i < 10000; i++) {
        imageSmoothing(img);
    }
    clock_t finishTimeVal = clock();
    printf("未作优化 执行10000次用时: %f 秒\n",
           (double)(finishTimeVal - startTimeVal) / CLOCKS_PER_SEC);

    // cpu优化
    clock_t startTimeVal1 = clock();
    for (int i = 0; i < 10000; i++) {
        imageSmoothing_CPUoptimize(img);
    }
    clock_t finishTimeVal1 = clock();
    printf("cpu优化 执行10000次用时: %f 秒\n",
           (double)(finishTimeVal1 - startTimeVal1) / CLOCKS_PER_SEC);

    // cache优化
    clock_t startTimeVal2 = clock();
    for (int i = 0; i < 10000; i++) {
        imageSmoothing_CacheOptimize(img);
    }
    clock_t finishTimeVal2 = clock();
    printf("cache优化 执行10000次用时: %f 秒\n",
           (double)(finishTimeVal2 - startTimeVal2) / CLOCKS_PER_SEC);

    // 复杂计算优化
    clock_t startTimeVal3 = clock();
    for (int i = 0; i < 10000; i++) {
        imageSmoothing_NormalOptimize(img);
    }
    clock_t finishTimeVal3 = clock();
    printf("复杂计算优化 执行10000次用时: %f 秒\n",
           (double)(finishTimeVal3 - startTimeVal3) / CLOCKS_PER_SEC);

    //     double startTimeVal8 = omp_get_wtime();
    //     {
    // #pragma omp parallel for num_threads(12)  // 将循环分为6个线程
    //         for (int i = 0; i < 10000; i++) {
    //             imageSmoothing(img);
    //         }
    //     }
    //     double finishTimeVal8 = omp_get_wtime();
    //     printf("多线程优化 执行10000次用时: %f 秒\n",
    //            (double)(finishTimeVal8 - startTimeVal8));

    return 0;
}
