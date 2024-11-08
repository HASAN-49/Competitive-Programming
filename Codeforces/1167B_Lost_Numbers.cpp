// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/problemset/problem/1167/B

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
    int a[6];
    int val[6] = {4, 8, 15, 16, 23, 42};
    int one = ask(1, 2);
    int two = ask(1, 3);
    int three = ask(1, 4);
    int four = ask(1, 5);
    map<int, bool> mp;
    int x = __gcd(one, two);
    int y = __gcd(three, four);
    a[0] = __gcd(x, y);
    if (a[0] == 30 || a[0] == 46) a[0] /= 2;
    a[1] = one / a[0];
    a[2] = two / a[0];
    a[3] = three / a[0];
    a[4] = four / a[0];
    for (int i = 0; i < 5; i++) {
        mp[a[i]] = true;
    }
    for (int i = 0; i < 6; i++) {
        if (!mp[val[i]]) a[5] = val[i];
    }
    cout << "!";
    for (int i = 0; i < 6; i++) {
        cout << ' ' << a[i];
    }
    cout << '\n';
    cout.flush();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
