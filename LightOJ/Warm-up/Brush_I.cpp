// Problem Link --> https://lightoj.com/problem/brush-1

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x > 0) ans += x;
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
