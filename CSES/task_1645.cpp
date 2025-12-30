// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1, 0), ans(n + 1, 0);
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (!stk.empty() && a[stk.top()] >= a[i]) {
      stk.pop();
    }
    if (!stk.empty()) ans[i] = stk.top();
    stk.push(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
