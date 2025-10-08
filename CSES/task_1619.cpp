// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<pair<int, int>> vp;

  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    vp.push_back({x, 1});
    vp.push_back({y + 1, -1});
  }

  sort(vp.begin(), vp.end());

  int mx = 0, cnt = 0;
  for (auto cur: vp) {
    cnt += cur.second;
    mx = max(mx, cnt);
  }

  cout << mx << '\n';

  return 0;
}
