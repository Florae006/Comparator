#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

typedef double ld;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1050;
const int inf = 0x3f3f3f;

char mp[maxn][maxn];
void solve() {
  int n, m;
  cin >> n >> m;
  int cntk = 0, cntd = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 'K')
        cntk++;
      else if (mp[i][j] == 'D')
        cntd++;
    }
  }
  if (cntk == cntd) {
    cout << "Draw\n";
  } else if (cntk > cntd) {
    cout << "Kokomi\n";
  } else {
    cout << "Dodola\n";
  }
}

void init() {}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t = 1;
  // cin >> t;
  // cin.get();
  while (t--)
    solve();

  return 0;
}
