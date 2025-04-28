// Problem Link --> https://lightoj.com/problem/old-sorting

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n; cin >> n;
  int a[n + 1], ans = 0;
  map<int, int> pos;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  vector<bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int cnt = 0, j = i;
    while (pos[j] != i) {
      vis[j] = true;
      cnt++;
      j = pos[j];
    }
    vis[j] = true;
    ans += cnt;
  }
  cout << "Case " << tc << ": ";
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
