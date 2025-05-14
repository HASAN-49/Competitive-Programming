// Problem Link --> https://lightoj.com/problem/intersection-of-cubes

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n; cin >> n;
  int xL = 1, xR = 1000, yL = 1, yR = 1000, zL = 1, zR = 1000;
  while (n--) {
    int x1, x2, y1, y2, z1, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    xL = max(xL, x1), xR = min(xR, x2);
    yL = max(yL, y1), yR = min(yR, y2);
    zL = max(zL, z1), zR = min(zR, z2);
  }
  int dx = max(0, xR - xL), dy = max(0, yR - yL), dz = max(0, zR - zL);
  int V = dx * dy * dz;
  cout << "Case " << tc << ": " << V << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
