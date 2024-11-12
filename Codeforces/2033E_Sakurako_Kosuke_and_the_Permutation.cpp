// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/problemset/problem/2033/E

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

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

void solve(int tc) {
    int n; cin >> n;

    int a[n+1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i || a[a[i]] == i) continue;
        ans++;
        int tmpp = a[a[i]];
        swap(a[a[i]], a[mp[i]]);
        int tmp = mp[i];
        mp[i] = a[i];
        mp[tmpp] = tmp;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
