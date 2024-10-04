// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1637

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

const int N = 1e6 + 9, inf = 1e9 + 9;
int dp[N];

int rec(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int m = n;
    int ans = inf;
    while (m > 0) {
        int x = m % 10;
        m /= 10;
        if (x == 0) continue;
        ans = min(ans, 1 + rec(n - x));
    }
    return dp[n] = ans;
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    int ans = rec(n);
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
