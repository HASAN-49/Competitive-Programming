// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

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
  long long n; cin >> n;
  long long ans = 0;
  int mod_inv = power(2, mod - 2);
  for (long long i = 1; i <= n; ) { // Time = O(2 * sqrt(n))
    long long q = n / i;
    long long next_i = n / q + 1;
    long long sum = (next_i - i) % mod * ((next_i - 1 + i) % mod) % mod * mod_inv % mod;
    ans += sum * q % mod;
    ans %= mod;
    i = next_i;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
