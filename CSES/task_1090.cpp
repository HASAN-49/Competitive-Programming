// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1090

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
  cout << "=>" << v.size() << '\n';
  for (auto x: v)
    cout << x << ' ';
  cout << '\n';
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int cnt = 0;
  bool vis[n] = {0};
  for (int i = 0, j = n - 1; i < n; i++) {
    if (vis[i]) continue;
    vis[i] = true, cnt++;
    while (j > i) {
      if (a[j] <= k - a[i]) {
        vis[j] = true;
        j--;
        break;
      }
      j--;
    }
  }
  cout << cnt << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
