// Problem Link --> https://lightoj.com/problem/juice-in-the-glass

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  int r1, r2, h, p; cin >> r1 >> r2 >> h >> p;
  double r = r2 + 1.0 * (r1 - r2) * p / h;
  double V = pi * p * (r2 * r2 + r2 * r + r * r) / 3.0;
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << V << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
