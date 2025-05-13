// Problem Link --> https://lightoj.com/problem/agent-j

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  double R1, R2, R3; cin >> R1 >> R2 >> R3;
  double a = R1 + R2, b = R2 + R3, c = R3 + R1;
  double s = (a + b + c) / 2.0;
  double area = sqrt(s * (s - a) * (s - b) * (s - c));
  double A = acos((a * a + c * c - b * b) / (2 * a * c));
  double B = acos((a * a + b * b - c * c) / (2 * a * b));
  double C = acos((b * b + c * c - a * a) / (2 * b * c));
  double area_prime = A / 2 * R1 * R1 + B / 2 * R2 * R2 + C / 2 * R3 * R3;
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << area - area_prime << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
