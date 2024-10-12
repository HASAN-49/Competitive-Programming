// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_g?lang=en

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
const int Mm = 998244353;
const int M = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e5 + 9;
vector<int> g[N];
int n, m, in[N], dp[N];

int dfs(int u) {
    int ans = 0;
    if (dp[u] != -1) return dp[u];
    for (auto v: g[u]) {
        ans = max(ans, 1 + dfs(v));
    }
    return dp[u] = ans;
}

void solve(int tc) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }
    int ans = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            ans = max(ans, dfs(i));
        }
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
