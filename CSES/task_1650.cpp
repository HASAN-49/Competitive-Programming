// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
long long t[4 * N];

void pull(int n, int l, int r) {
  t[n] = t[l];
  t[n] ^= t[r];
}

long long query(int n, int b, int e, int i, int j) {
  if (b > j || e < i) return 0;
  if (b >= i && e <= j) return t[n];
  int l = 2 * n, r = 2 * n + 1;
  int mid = b + (e - b) / 2;
  return query(l, b, mid, i, j) ^ query(r, mid + 1, e, i, j);
}

void upd(int n, int b, int e, int i, int v) {
  if (b > i || e < i) return;
  if (b == i && e == i) {
    t[n] = v;
    return;
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = b + (e - b) / 2;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
  pull(n, l, r);
}

void build(int n, int b, int e) {
  if (b == e) {
    t[n] = a[b];
    return;
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = b + (e - b) / 2;
  build(l, b, mid);
  build(r, mid + 1, e);
  pull(n, l, r);
}

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  build(1, 1, n);
  while (q--) {
    int l, r; cin >> l >> r;
    // cout << query(1, 1, n, l, r) << '\n';
    int ans = a[r] ^ a[l - 1];
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
