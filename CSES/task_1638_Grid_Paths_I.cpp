// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1638

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

const int N = 1005;
string s[N];
int n, dp[N][N];

int rec(int i, int j) {
    if (i == n || j == n || s[i][j] == '*') return 0;
    if (i == n - 1 && j == n - 1) return 1;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = ((rec(i + 1, j) % M) + (rec(i, j + 1) % M)) % M;
    return ans;
}

void solve(int tc) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
