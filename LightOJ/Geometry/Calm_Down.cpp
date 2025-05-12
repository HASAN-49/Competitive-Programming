// Problem Link --> https://lightoj.com/problem/calm-down

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  double R; cin >> R;
  int n; cin >> n;
  double r = R * sin(pi / n) / (1 + sin(pi / n));
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
