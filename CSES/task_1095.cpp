// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int mod = 1e9 + 7;

int power(int a, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return res;
}

void solve() {
  int a, b; cin >> a >> b;
  cout << power(a, b) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test 
  solve();

  return 0;
}
