// Problem Link --> https://www.spoj.com/problems/TDPRIMES/

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 1e8 + 1;
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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  int k = 0;
  for (auto p: primes) {
    if (k == 0) cout << p << '\n';
    k++;
    if (k == 100) k = 0;
  }

  return 0;
}
