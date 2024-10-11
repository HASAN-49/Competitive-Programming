// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/divisible-group-sums

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

const int N = 205;
int n, q, d, m, a[N];
long long dp[N][N][25];

long long rec(int i, int cnt, int sum) {
    if (cnt > m) return 0;
    if (i == n + 1) {
        if (cnt == m && sum == 0) return 1;
        return 0;
    }
    long long &ans = dp[i][cnt][sum];
    if (ans != -1) return ans;
    ans = rec(i + 1, cnt, sum);
    ans += rec(i + 1, cnt + 1, (sum + a[i] % d + d) % d);
    return ans;
}

void solve(int tc) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Case " << tc << ":\n";
    while (q--) {
        memset(dp, -1, sizeof dp);
        cin >> d >> m;
        long long ans = rec(1, 0, 0);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
