// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/contest/2028/problem/A

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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < n * 20; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == 'N') y++;
            else if (s[j] == 'S') y--;
            else if (s[j] == 'E') x++;
            else x--;
            // cout << s[j] << ' ' << x << ' ' << y << ' ' << a << ' ' << b << '\n';
            if (x == a && y == b) {
                yes;
                return;
            }
        }
    }
    no;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
