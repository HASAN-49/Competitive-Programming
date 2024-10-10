// بسم الله الرحمن الرحيم
// Problem Link --> https://www.codechef.com/problems/STRFIRSTCHAR

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

void solve(int tc) {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    if (s == t) {
        cout << "0\n";
        return;
    }
    if (s[0] != t[0]) {
        cout << "-1\n";
        return;
    }
    int k;
    for (k = 0; k < min(n, m); k++) {
        if (s[k] != t[k]) break;
    }
    if (k == min(n, m)) {
        cout << "1\n";
        return;
    }
    // cout << k << ' ';
    for (int i = n-1, j = m - 1; i >= k && j >= k; i--, j--) {
        if (s[i] != t[j]) {
            cout << "2\n";
            return;
        }
    }
    cout << "1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
