// Problem Link --> https://lightoj.com/problem/minimum-arc-distance

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define pi 3.14159265358979323846

void solve(int tc) {
  double Ox, Oy, Ax, Ay, Bx, By; 
  cin >> Ox >> Oy >> Ax >> Ay >> Bx >> By;
  double OA = sqrt((Ox - Ax) * (Ox - Ax) + (Oy - Ay) * (Oy - Ay));
  double OB = sqrt((Ox - Bx) * (Ox - Bx) + (Oy - By) * (Oy - By));
  double AB = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
  double theta = acos((OA * OA + OB * OB - AB * AB) / (2 * OA * OB));
  double s = OA * theta;
  cout << "Case " << tc << ": ";
  cout << fixed << setprecision(10) << s << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
