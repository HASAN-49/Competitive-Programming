// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  long long k = 1, pre[64] = {0};
  int id = 1;
  while (n >= k) {
    pre[id] = pre[id - 1] * 2 + k;
    k *= 2;
    id++;
  }
  long long ans = 0;
  id--, k /= 2;
  while (n > 0 && id--) {
    long long m = n + 1;
    if (m == 2 * k) {
      ans += pre[id] * 2 + k;
      break;
    }
    ans += pre[id];
    m -= k;
    ans += m;
    n = n - k;
    while (m < k) {
      k /= 2;
      id--;
    }
    if (m == k) {
      ans += pre[id];
      break;
    }
    id++;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
