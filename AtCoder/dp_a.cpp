// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/tessoku-book/tasks/dp_a?lang=en

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
int h[N];

void solve(int tc) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(abs(h[i] - h[i-1]) + dp[i-1], abs(h[i] - h[i-2]) + dp[i-2]);
    }
    cout << dp[n] << '\n';
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
