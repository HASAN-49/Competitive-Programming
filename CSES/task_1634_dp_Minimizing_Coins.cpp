// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1634

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

const int N = 105, M = 1e6 + 9, inf = 1e9 + 9;
int n, a[N];
int dp[N][M];
int rdp[2][M];

int f(int i, int s) {
    if (i == n + 1) {
        if (s == 0) return 0;
        return inf;
    }
    if (dp[i][s] != -1) return dp[i][s];
    int ans = f(i + 1, s);
    if (s >= a[i]) ans = min(ans, 1 + f(i, s - a[i]));
    return dp[i][s] = ans;
}

void solve(int tc) {
    cin >> n;
    int x; cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // memset(dp, -1, sizeof dp);
    // int ans = f(1, x);
    // if (ans < inf) cout << ans << '\n';
    // else cout << "-1\n";

    // Iterative takes less time than recursive
    for (int i = n + 1; i >= 1; i--) {
        // This is a solution that is accepted. We can reduce the memory
        // for (int s = 0; s <= x; s++) {
        //     int &ans = dp[i][s];
        //     if (i == n + 1) {
        //         if (s == 0) ans = 0;
        //         else ans = inf;
        //     }
        //     else {
        //         ans = dp[i + 1][s];
        //         if (s >= a[i]) ans = min(ans, 1 + dp[i][s - a[i]]);
        //     }
        // }

        // Code for reducing memory by using 2 * M size rdp array
        for (int s = 0; s <= x; s++) {
            int &ans = rdp[0][s];
            if (i == n + 1) {
                if (s == 0) ans = 0;
                else ans = inf;
            }
            else {
                ans = rdp[1][s];
                if (s >= a[i]) ans = min(ans, 1 + rdp[0][s - a[i]]);
            }
        }
        for (int s = 0; s <= x; s++) {
            rdp[1][s] = rdp[0][s];
        }
    }
    // if (dp[1][x] < inf) cout << dp[1][x] << '\n';
    if (rdp[0][x] < inf) cout << rdp[0][x] << '\n';
    else cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
