// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
long long t[N * 4], lazy[N * 4];

void push(int n, int b, int e) {
  if (lazy[n] == 0) {
    return;
  }
  t[n] += lazy[n];
  if (b != e) {
    int l = n * 2, r = n * 2 + 1;
    lazy[l] += lazy[n];
    lazy[r] += lazy[n];
  }
  lazy[n] = 0;
}

long long merge(long long l, long long r) {
  return l + r;
}

long long query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if (b > j || e < i) return 0;
  if (b >= i && e <= j) return t[n];
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void upd(int n, int b, int e, int i, int j, int v) {
  push(n, b, e);
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    lazy[n] = v;
    push(n, b, e);
    return;
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
  t[n] = merge(t[l], t[r]);
}

void build(int n, int b, int e) {
  lazy[n] = 0;
  if (b == e) {
    t[n] = a[b];
    return;
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void solve() {
  int n; cin >> n;
  int q; cin >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 2) {
      int l; cin >> l;
      cout << query(1, 1, n, l, l) << '\n';
    }
    else {
      int l, r, v; cin >> l >> r >> v;
      upd(1, 1, n, l, r, v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
