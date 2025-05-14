// Problem Link --> https://lightoj.com/problem/trapezium

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  double a, b, c, d; cin >> a >> b >> c >> d;
  double k = a - c;
  double x = (d * d + k * k - b * b) / (2 * k);
  double h = sqrt(d * d - x * x);
  double area = 0.5 * (a + c) * h;
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << area << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
