/*
 * 对拍器
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // int testcase = 20; // 设置对拍组数
    while (true) {
        system("data > data.out");
        system("stds.exe < data.out > stds.out"); // 运行std.exe,从data.out读入数据,把结果输入到std.out
        system("test.exe < data.out > test.out"); // 运行test.exe,从data.out读入数据,把结果输入到test.out
        if (system("fc stds.out test.out")) { // 比较std.out和test.out
            system("pause");
        }
    }

    return 0;
}