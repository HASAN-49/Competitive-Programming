// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/problemset/problem/1999/G1

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

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve(int tc) {
    int l = 2, r = 999, ans = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        int res = ask(1, mid);
        if (res == mid) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << "! " << l << '\n';
    cout.flush();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
