// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/problemset/problem/679/A

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

string ask(int val) {
    cout << val << '\n';
    cout.flush();
    string x; cin >> x;
    return x;
}

void solve(int tc) {
    int cnt = 0;
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for (int i = 0; i < 15; i++) {
        if (ask(p[i]) == "yes") {
            cnt++;
            if (p[i] * p[i] <= 100 && ask(p[i] * p[i]) == "yes") cnt++;
        }
    }
    if (cnt >= 2) cout << "composite\n";
    else cout << "prime\n";
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
