// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int divisors[N];

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    for (int j = 1; 1LL * j * j <= x; j++) { // log(N)
      if (x % j == 0) {
        divisors[j] += 1;
        if (1LL * j * j != x) divisors[x / j] += 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (divisors[i] > 1) ans = i;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
