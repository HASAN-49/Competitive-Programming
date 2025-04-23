// Problem Link --> https://lightoj.com/problem/false-ordering

#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1001;
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

vector<pair<int, int>> ans;
void fn() {
  for (int i = 1; i < N; i++) {
    int fac = 1, x = i;
    for (auto p: primes) {
      int e = 0;
      while (x % p == 0) {
        e++;
        x /= p;
      }
      fac *= (e + 1);
    }
    if (x - 1) fac *= 2;
    ans.push_back({fac, i});
  }
}

bool cmp(pair<int, int> &x, pair<int, int> &y) {
  if (x.first == y.first) return x.second > y.second;
  return x.first < y.first;
}

void solve(int tc) {
  int n; cin >> n;
  cout << "Case " << tc << ": ";
  cout << ans[n- 1].second << '\n';
} 

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  fn();
  sort(ans.begin(), ans.end(), cmp);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
