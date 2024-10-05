// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_c?lang=en

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
int a[N][4], n, dp[N][4];

int rec(int i, int last) {
    if (i == n + 1) return 0;
    int &ans = dp[i][last];
    if (ans != -1) return ans;
    ans = 0;
    for (int j = 1; j <= 3; j++) {
        if (j == last) continue;
        ans = max(ans, a[i][j] + rec(i + 1, j));
    }
    return ans;
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
    cout << rec(1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
