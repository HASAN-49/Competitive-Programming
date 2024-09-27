// problem link --> https://www.spoj.com/problems/GSS3/en/

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'

#define pi 3.14159265358979323846
#define M 1e9 + 7;
#define Mm 998244353

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 5e4 + 9, inf = 1e9 + 9;
int a[N];

struct node {
    int total_sum, max_sum, max_suffix, max_prefix;
};

node t[N * 4];

node merge(node l, node r) {
    if (l.total_sum == inf) return r;
    if (r.total_sum == inf) return l;
    node ans;
    ans.total_sum = l.total_sum + r.total_sum;
    ans.max_sum = max({l.max_sum, r.max_sum, l.max_suffix + r.max_prefix});
    ans.max_prefix = max(l.max_prefix, l.total_sum + r.max_prefix);
    ans.max_suffix = max(r.max_suffix, r.total_sum + l.max_suffix);
    return ans;
}

void build(int n, int b, int e) {
    if (b == e) {
        t[n].total_sum = a[b];
        t[n].max_sum = a[b];
        t[n].max_prefix = a[b];
        t[n].max_suffix = a[b];
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int v) {
    if (b > i || e < i) return;
    if (b == i && e == i) {
        t[n].total_sum = v;
        t[n].max_sum = v;
        t[n].max_prefix = v;
        t[n].max_suffix = v;
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    upd(l, b, mid, i, v);
    upd(r, mid + 1, e, i, v);
    t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {inf, inf, inf, inf};
    if (b >= i && e <= j) return t[n];
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int tc) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int ty; cin >> ty;
        if (ty == 0) {
            int i, v; cin >> i >> v;
            // update
            upd(1, 1, n, i, v);
        }
        else {
            int l, r; cin >> l >> r;
            // query
            auto ans = query(1, 1, n, l, r);
            cout << ans.max_sum << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
