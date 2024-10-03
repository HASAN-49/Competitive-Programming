// Problem link --> https://atcoder.jp/contests/dp/tasks/dp_g

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
#define Mm 998244353
const int M = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e5 + 9;
vector<int> g[N];
int dp[N];

int rec(int u) {
    if (dp[u] != -1) return dp[u];
    int ans = 0;
    // cout << "par=" << u << '\n';
    for (auto v: g[u]) {
        // cout << "par=" << u << " child=" << v << '\n';
        ans = max(ans, 1 + rec(v));
    }
    return dp[u] = ans;
}

void solve(int tc) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, rec(i));
        // cout << rec(i) << '\n';
    }
    cout << mx << '\n';
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
