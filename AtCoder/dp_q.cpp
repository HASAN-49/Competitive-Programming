//بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_q?lang=en

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
#define Mm 998244353
const int M = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e6 + 9;
long long dp[N];
long long t[N * 4];

void upd(int n, int b, int e, int i, long long v) {
    if (b > i || e < i) return;
    if (b == i && e == i) {
        t[n] = max(t[n], v);
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    upd(l, b, mid, i, v);
    upd(r, mid + 1, e, i, v);
    t[n] = max(t[l], t[r]);
}

long long query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0LL;
    if (b >= i && e <= j) return t[n];
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int tc) {
    int n; cin >> n;
    int h[n+1], a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        if (h[i] != 1) {
            long long mx = query(1, 1, N, 1, h[i] - 1);
            mx += a[i];
            dp[i] = max(mx, dp[i]);
        }
        upd(1, 1, N, h[i], dp[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
