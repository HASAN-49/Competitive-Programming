// Problem Link --> https://lightoj.com/problem/higher-math

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int a, b, c; cin >> a >> b >> c;
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  cout << "Case " << tc << ": ";
  if (a * a + b * b == c * c) cout << "yes\n";
  else cout << "no\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
