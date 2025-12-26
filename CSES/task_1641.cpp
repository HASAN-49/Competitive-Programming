// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, x; cin >> n >> x;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    a[i] = {val, i};
  }
  sort(a.begin() + 1, a.end());
  // for (int i = 1; i <= n; i++) {
  //   cout << a[i].first << ' ' << a[i].second << '\n';
  // }
  for (int i = 1; i <= n && a[i].first <= x; i++) {
    for (int j = 1; j < i && a[i].first + a[j].first <= x; j++) {
      int sum = a[i].first + a[j].first;
      int k = upper_bound(a.begin() + 1, a.end(), make_pair(x - sum - 1, n)) - a.begin();
      if (k < j && a[k].first == x - sum) {
        cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second << '\n';
        return;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  solve();
 
  return 0;
}
