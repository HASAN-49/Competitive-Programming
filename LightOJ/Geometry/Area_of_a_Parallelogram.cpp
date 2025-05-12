// Problem Link --> https://lightoj.com/problem/area-of-a-parallelogram

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int ax, ay, bx, by, cx, cy, dx, dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  dx = ax - bx + cx, dy = ay - by + cy;
  int area = ax * by - bx * ay + bx * cy - cx * by + cx * dy - cy * dx + dx * ay - ax * dy;
  cout << "Case " << tc << ": ";
  cout << dx << ' ' << dy << ' ' << abs(area) / 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
