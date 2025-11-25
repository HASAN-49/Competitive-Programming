// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  map<int, bool> mp;
  int cnt = 0, mx = 0;
  for (int i = 0, j = 0; i < n; i++) {
    cin >> a[i];
    while (mp[a[i]]) {
      cnt--;
      mp[a[j++]] = false;
    }
    cnt++;
    mp[a[i]] = true;
    mx = max(mx, cnt);
  }
  cout << mx << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
