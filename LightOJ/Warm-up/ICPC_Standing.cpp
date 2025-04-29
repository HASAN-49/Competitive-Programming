// Problem Link --> https://lightoj.com/problem/icpc-standing

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int p, s, r; cin >> p >> s >> r;
  cout << "Case " << tc << ": ";
  if (p == s && r != 1) cout << "No\n";
  else cout << "Yes\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
