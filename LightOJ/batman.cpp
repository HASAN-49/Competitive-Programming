// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/batman

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

const int N = 55;
string a, b, c;
int dp[N][N][N];
int n, m, sz;

int lcs(int i, int j, int k) {
    if (i == n || j == m || k == sz) return 0;
    int &ans = dp[i][j][k];
    if (ans != -1) return ans;
    ans = 0;
    if (a[i] == b[j] && b[j] == c[k]) {
        ans = max(ans, 1 + lcs(i + 1, j + 1, k + 1));
    }
    else {
        ans = max(ans, lcs(i + 1, j, k));
        ans = max(ans, lcs(i, j + 1, k));
        ans = max(ans, lcs(i, j, k + 1));
    }
    return ans;
}

void solve(int tc) {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), sz = c.size();
    memset(dp, -1, sizeof dp);
    cout << "Case " << tc << ": ";
    cout << lcs(0, 0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
