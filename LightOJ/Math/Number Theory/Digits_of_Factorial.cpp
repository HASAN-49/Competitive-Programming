// Problem Link --> https://lightoj.com/problem/digits-of-factorial

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 1e6 + 9;
double pre[N];

void pre_calculate() {
  for (int i = 1; i < N; i++) {
    pre[i] = pre[i - 1] + log(i);
  }
}

void solve(int tc) {
  int n, base; cin >> n >> base;
  double ans = pre[n] / log(base);
  cout << "Case " << tc << ": ";
  cout << (int) ans + 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre_calculate();
  int k = 1;
  test 
  solve(k++);

  return 0;
}
