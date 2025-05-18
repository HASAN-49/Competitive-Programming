// Problem Link --> https://lightoj.com/problem/olympics

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  double a, b; char ch; cin >> a >> ch >> b;
  double r = 0.5 * sqrt(a * a + b * b);
  double theta = acos((2 * r * r - b * b) / (2 * r * r));
  double s = r * theta;
  double k = 200.0 / (a +  s);
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << a * k << ' ' << b * k << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
