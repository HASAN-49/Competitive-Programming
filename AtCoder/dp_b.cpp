// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_b?lang=en

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

const int N = 1e5 + 9, inf = 1e9 + 9;
int dp[N];
int n, k, h[N];

int rec(int i) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = inf;
    for (int j = i + 1, cnt = 0; cnt < k && j <= n; j++, cnt++) {
        int abs_val = abs(h[i] - h[j]);
        ans = min(ans, abs_val + rec(j));
    }
    return dp[i] = ans;
}

void solve(int tc) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i] = inf;
    }

    // Iterative Solution

    // dp[1] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i + 1, cnt = 0; cnt < k && j <= n; j++, cnt++) {
    //         int abs_val = abs(h[i] - h[j]);
    //         dp[j] = min(dp[j], abs_val + dp[i]);
    //     }
    // }
    // cout << dp[n] << '\n';


    // Recursive Solution
    memset(dp, -1, sizeof dp);
    cout << rec(1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
