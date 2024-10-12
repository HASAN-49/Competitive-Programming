// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_p?lang=en

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
int n, start, dp[N][2];

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for (auto v: g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % M;
            dp[u][1] = 1LL * dp[u][1] * dp[v][0] % M;
        }
    }
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    start = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            start = i;
            break;
        }
    }
    dfs(start, 0);
    ll ans = dp[start][0] + dp[start][1];
    cout << ans % M << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
