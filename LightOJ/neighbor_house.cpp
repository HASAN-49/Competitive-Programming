// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/neighbor-house

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

const int N = 25, inf = 1e9;
int c[N][4], dp[N][N], n;

int rec(int i, int last) {
    if (i == n + 1) return 0;
    int &ans = dp[i][last];
    if (ans != -1) return dp[i][last];
    ans = inf;
    for (int k = 1; k <= 3; k++) {
        if (k == last) continue;
        ans = min(ans, c[i][k] + rec(i + 1, k));
    }
    // cout << ans << '\n';
    return ans;
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i][1] >> c[i][2] >> c[i][3];
    }
    cout << "Case " << tc << ": ";
    cout << rec(1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
