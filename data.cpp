/*
 * 对拍样例：生成随机数
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Random(ll mod) {
    // 生成范围在[0,mod)的数
    ll ans = 2147483647;
    return ans = ans * rand() % mod;
}

int main() {
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);

    ll m = 50;

    int a = Random(m);
    int b = Random(m);
    cout << a << " " << b << "\n";

    return 0;
}