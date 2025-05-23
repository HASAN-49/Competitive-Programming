// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_e?lang=en

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

const int N = 105, inf = 1e9 + 9;
int n, W, w[N], v[N], dp[N][N * 1000 + 5];

int rec(int i, int val) {
    if (i == n + 1) {
        if (val == 0) return 0;
        return inf;
    }
    int &ans = dp[i][val];
    if (ans != -1) return ans;
    ans = min(rec(i + 1, val), w[i] + rec(i + 1, val - v[i]));
    return ans;
}

void solve(int tc) {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int ans = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n * 1000; i++) {
        if (rec(1, i) <= W) ans = max(ans, i);
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
