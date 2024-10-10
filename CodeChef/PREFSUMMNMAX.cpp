// بسم الله الرحمن الرحيم
// Problem Link --> https://www.codechef.com/problems/PREFSUMMNMAX

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
    int n; cin >> n;
    int a[n+1], sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i == 1) continue;
        a[i] = x - sum;
        sum = sum + a[i];
        // cout << sum << ' ';
    }
    a[1] = 2e6;
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
