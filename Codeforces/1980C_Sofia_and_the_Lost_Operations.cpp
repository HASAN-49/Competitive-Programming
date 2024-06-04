// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)
#define ll long long
 
#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "
 
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'
 
#define pi 3.14159265358979323846
const int mod = 1e9 + 9;
 
int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};
int emx[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
int emy[9] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve(int tt) {
    int n; cin >> n;
    int a[n], b[n];
    set<int> st;
    map<int, int> mp, mpp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i]) {
            st.insert(b[i]);
            mp[b[i]]++;
        }
        mpp[b[i]] = 1;
    }
    int m; cin >> m;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (mpp[x] == 1) {
            mp[x] = max(mp[x]-1, 0);
            ok = true;
        }
        else ok = false;
    }
    int cnt = 0;
    for (auto x: st) {
        cnt += mp[x];
    }
    // cout << cnt << ' ' << ok << ' ';
    if (cnt > 0 || !ok) no;
    else yes;
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
