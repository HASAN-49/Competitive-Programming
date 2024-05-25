// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

void solve(int tt) {
    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a, a+n);
    int g = -1;
    for (int i = 0; i < n; i++) {
        if (a[i]%a[0] != 0) {
            if (g == -1) g = a[i];
            g = __gcd(g, a[i]);
        }
    }
    if (g == -1 || mp[g] >= 1) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    test solve(k++);
    return 0;
}
