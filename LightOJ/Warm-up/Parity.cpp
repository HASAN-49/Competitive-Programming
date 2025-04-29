// Problem Link --> https://lightoj.com/problem/parity

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n, ans = 0; cin >> n;
  while (n) {
    if (n & 1) ans++;
    n >>= 1;
  }
  cout << "Case " << tc << ": ";
  if (ans & 1) cout << "odd\n";
  else cout << "even\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
