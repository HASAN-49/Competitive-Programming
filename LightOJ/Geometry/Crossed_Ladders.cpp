// Problem Link --> https://lightoj.com/problem/crossed-ladders

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  double x, y, c; cin >> x >> y >> c;
  double low = 0, high = max(x, y), w = 0;
  for (int i = 0; i < 32; i++) {
    double mid = (low + high) / 2.0;
    double a = sqrt(x * x - mid * mid);
    double b = sqrt(y * y - mid * mid);
    if (1.0 / c >= 1.0 / a + 1.0 / b) {
      w = mid;
      low = mid;
    }
    else {
      high = mid;
    }
  }
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << w << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
