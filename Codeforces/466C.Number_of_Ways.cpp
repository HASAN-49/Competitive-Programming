// بسم الله الرحمن الرحيم
// Problem Link --> https://codeforces.com/contest/466/problem/C

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

const int N = 5e5 + 5;
ll pref[N];

void solve(int tc) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    if (pref[n] % 3) {
        cout << "0\n";
    }
    else {
        ll sum = pref[n] / 3, ans = 0;
        int cnt = 0;
        for (int j = 2; j < n; j++) {
            cnt += pref[j-1] == sum;
            if (pref[j] == 2 * sum) {
                ans += cnt;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
