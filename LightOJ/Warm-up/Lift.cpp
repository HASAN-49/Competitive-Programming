// Problem Link --> https://lightoj.com/problem/lift

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int a, b; cin >> a >> b;
  int ans = (abs(a - b) + a) * 4 + 19;
  cout << "Case " << tc << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
