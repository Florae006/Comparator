#include <bits/stdc++.h>

using namespace std;

// default judge: check std == test
int main() {
  freopen("result.out", "a", stdout);

  ifstream stds("stds.out");
  ifstream test("test.out");

  if (!stds.is_open() || !test.is_open()) {
    cerr << "Error opening files." << endl;
    return 1;
  }

  string sc;
  string s1 = "", s2 = "";

  while (getline(stds, sc)) {
    while (!sc.empty() && (sc.back() == ' ' || sc.back() == '\n'))
      sc.pop_back(); // ignore enter and space
    if (!sc.empty())
      s1 += sc + '\n';
  }
  while (getline(test, sc)) {
    while (!sc.empty() && (sc.back() == ' ' || sc.back() == '\n'))
      sc.pop_back(); // ignore enter and space
    if (!sc.empty())
      s2 += sc + '\n';
  }

  while (!s1.empty() && s1.back() == '\n')
    s1.pop_back();
  while (!s2.empty() && s2.back() == '\n')
    s2.pop_back();

  if (s1 == s2) {
    cout << "Accepted" << endl;
  } else {
    cout << "Rejected" << endl;
  }

  return 0;
}