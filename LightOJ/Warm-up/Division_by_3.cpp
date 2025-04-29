// Problem Link --> https://lightoj.com/problem/division-by-3

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int a, b; cin >> a >> b;
  int ans = (b - a + 1) / 3;
  a = a + ans * 3 - 1;
  ans *= 2;
  while (b > a) {
    if (b % 3 != 1) ans++;
    b--;
  }
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
