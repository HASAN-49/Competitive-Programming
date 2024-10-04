// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/hex-a-bonacci

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
const int M = 10000007;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e6 + 9;
int dp[N];

int a, b, c, d, e, f;

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if (dp[n] != -1) return dp[n];
    dp[n] = fn(n - 1) % M;
    dp[n] = (dp[n] + fn(n - 2)) % M;
    dp[n] = (dp[n] + fn(n - 3)) % M;
    dp[n] = (dp[n] + fn(n - 4)) % M;
    dp[n] = (dp[n] + fn(n - 5)) % M;
    dp[n] = (dp[n] + fn(n - 6)) % M;
    return dp[n];
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    cout << "Case " << tc << ": ";
    cout << fn(n) % M << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int k = 1;
    test 
    solve(k++);

    return 0;
}
