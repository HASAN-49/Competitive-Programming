// Problem Link --> https://www.spoj.com/problems/VECTAR8/

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bitset<N> f;
vector<int> primes;

bool check_zero(int n) {
  while (n) {
    if (n % 10 == 0) return true;
    n /= 10;
  }
  return false;
}

bool check_suffix(int n) {
  int k = 10;
  for (int i = 0; i < 5; i++) {
    int val = n % k;
    if (f[val]) return true;
    k *= 10;
  }
  return false;
}

void sieve() {
  f[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!f[i]) {
      for (int j = i * i; j < N; j += i) {
        f[j] = true;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (!f[i] && !check_zero(i) && !check_suffix(i)) {
      primes.push_back(i);
    }
  }
}

void solve() {
  int n; cin >> n;
  int ans = lower_bound(primes.begin(), primes.end(), n + 1) - primes.begin();
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  int t; cin >> t;
  while (t--) solve();

  return 0;
}
