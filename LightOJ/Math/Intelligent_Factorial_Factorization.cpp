// Problem Link --> https://lightoj.com/problem/intel-factor-factorization

#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 105;
bitset<N> f;
vector<int> primes;

void sieve() {
  // int n = N - 9;
  f[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!f[i]) {
      for (int j = i * i; j < N; j += i) {
        f[j] = true;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (!f[i]) {
      primes.push_back(i);
    }
  }
}

void solve(int tc) {
  int n; cin >> n;
  int ans = 0;
  map<int, int> mp;
  for (auto p: primes) {
    int x = n;
    while (x) {
      mp[p] += x / p;
      x /= p;
    }
  }
  cout << "Case " << tc << ": " << n << " =";
  bool ok = false;
  for (auto curr: mp) {
    if (curr.second) {
      if (ok) cout << " *";
      cout << ' ' << curr.first << " (" << curr.second << ")";
      ok = true;
    }
  }
  cout << '\n';
} 

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  // cout << primes.size() << '\n';

  int k = 1;
  test 
  solve(k++);

  return 0;
}
