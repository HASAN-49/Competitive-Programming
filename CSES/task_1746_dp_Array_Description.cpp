// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1746

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
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e5 + 9, M = 105;
int n, m, a[N], dp[M][N];

int f(int i, int last) {
    if (i == n + 1) return 1;
    int &ans = dp[last][i];
    if (ans != -1) return ans;
    ans = 0;
    int l = 1, r = m;
    if (a[i] > 0) l = r = a[i];
    else if (i != 1) l = max(l, last - 1), r = min(r, last + 1);
    for (int cur = l; cur <= r; cur++) {
        if (i == 1 || abs(cur - last) <= 1) {
            ans += f(i + 1, cur);
            ans %= mod;
        }
    }
    return ans;
}

void solve(int tc) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // memset(dp, -1, sizeof dp);
    // cout << f(1, 0) << '\n';


    // Iterative dp
    for (int i = 1; i <= m; i++) {
        dp[i][n+1] = 1;
    }
    for (int i = n; i > 0; i--) {
        for (int last = 1; last <= m; last++) {
            int &ans = dp[last][i];
            ans = 0;
            int l = 1, r = m;
            if (a[i] > 0) l = r = a[i];
            else if (i != 1) l = max(l, last - 1), r = min(r, last + 1);
            for (int cur = l; cur <= r; cur++) {
                if (i == 1 || abs(cur - last) <= 1) {
                    ans += dp[cur][i+1];
                    ans %= mod;
                }
            }
        }
    }
    cout << dp[1][1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
