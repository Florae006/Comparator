/*
 * 对拍测试程序
 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;cin >> a >> b;
    int c = a + b;
    if (a % 2)c++;
    cout << c << endl;

    return 0;
}