// Problem link --> https://atcoder.jp/contests/dp/tasks/dp_f

// بسم الله الرحمن الرحيم
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
#define M 1e9 + 7;
#define Mm 998244353

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

string s, t;
int n, m;
const int N = 3005, inf = 1e9 + 7;
int dp[N][N];

int lcs(int i, int j) {
    if (i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = max(lcs(i + 1, j), lcs(i, j + 1));
    if (s[i] == t[j]) {
        ans = max(ans, lcs(i + 1, j + 1) + 1);
    }
    return dp[i][j] = ans;
}

void print(int i, int j) {
    if (i >= n || j >= m) return;
    if (s[i] == t[j]) {
        cout << s[i];
        print(i + 1, j + 1);
        return;
    }
    int x = lcs(i + 1, j);
    int y = lcs(i, j + 1);
    if (x >= y) print(i + 1, j);
    else print(i, j + 1);
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    cin >> s >> t;
    n = s.size(), m = t.size();
    // int ans = lcs(0, 0);
    // cout << ans << '\n';
    print(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
