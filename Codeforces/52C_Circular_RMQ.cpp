// Problem link --> https://codeforces.com/problemset/problem/52/C

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

const int N = 2e5 + 9;
const long long inf = 1e13 + 9;
int a[N];
long long t[N * 4], lazy[N * 4];

void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] += lazy[n];
    if (b != e) {
        int l = n * 2, r = n * 2 + 1;
        lazy[l] += lazy[n];
        lazy[r] += lazy[n];
    }
    lazy[n] = 0;
}

void build(int n, int b, int e) {
    if (b == e) {
        t[n] = a[b];
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = min(t[l], t[r]);
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
    t[n] = min(t[l], t[r]);
}

long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return t[n];
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int tc) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q; cin >> q;
    cin.ignore();
    while (q--) {
        string line; getline(cin, line);
        stringstream ss(line);
        int l, r, v;
        ss >> l >> r;
        l++, r++;
        if (ss >> v) {
            if (l <= r) upd(1, 1, n, l, r, v);
            else {
                upd(1, 1, n, 1, r, v);
                upd(1, 1, n, l, n, v);
            }
        }
        else {
            long long ans = inf;
            if (l <= r) ans = query(1, 1, n, l, r);
            else {
                ans = min(query(1, 1, n, 1, r), query(1, 1, n, l, n));
            }
            cout << ans << '\n';
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
