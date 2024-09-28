// Problem link --> https://www.spoj.com/problems/DQUERY/en/

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

const int N = 3e4 + 9, QN = 2e5 + 9;
int a[N], ans[QN], t[N * 4];
vector<pair<int, int>> Q[QN];

void build(int n, int b, int e) {
    if (b == e) {
        t[n] = 0;
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];
}

void upd(int n, int b, int e, int i, int v) {
    if (b > i || e < i) return;
    if (b == i && e == i) {
        t[n] = v;
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    upd(l, b, mid, i, v);
    upd(r, mid + 1, e, i, v);
    t[n] = t[l] + t[r];
}

int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void solve(int tc) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        Q[r].push_back({l, i});
    }
    map<int, int> mp;
    for (int r = 1; r <= n; r++) {
        if (mp.find(a[r]) != mp.end()) {
            // update(-1);
            upd(1, 1, n, mp[a[r]], 0);
        }
        // upd(+1);
        mp[a[r]] = r;
        upd(1, 1, n, r, 1);
        for (auto curr: Q[r]) {
            int l = curr.first, id = curr.second;
            ans[id] = query(1, 1, n, l, r);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
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
