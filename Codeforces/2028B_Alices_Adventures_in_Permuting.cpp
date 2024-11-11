// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/contest/2028/problem/B

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

void solve(int tc) {
    ll n, b, c; cin >> n >> b >> c;
    if (b) {
        cout << n - max(0LL, (n - c + (b - 1)) / b) << '\n';
    }
    else {
        if (c >= n) cout << n << '\n';
        else if (c >= n - 2) cout << n - 1 << '\n';
        else cout << "-1\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
