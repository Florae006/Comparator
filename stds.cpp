/*
 * 对拍标程:一般是个暴力
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;cin >> a >> b;
    
    int c = 0;
    for (int i = 1;i <= a;i++) {
        c++;
    }
    for (int i = 1;i <= b;i++) {
        c++;
    }

    cout << c << endl;

    return 0;
}