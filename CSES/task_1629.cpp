// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    int b, e; cin >> b >> e;
    vp.push_back({b, e});
  }
  sort(vp.begin(), vp.end(), cmp);
  int ans = 0, last = 0;
  for (auto cur: vp) {
    if (cur.first >= last) {
      ans++;
      last = cur.second;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
