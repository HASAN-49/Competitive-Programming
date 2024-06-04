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
    int n, f, k; cin >> n >> f >>k;
    vector<int> a(n+1);
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vp.push_back({a[i], i});
    }
    sort(all(vp));
    reverse(all(vp));
    for (int i = k; i < n; i++) {
        if(vp[i].first == a[f] && vp[i-1].first == a[f]) {
            cout << "MAYBE\n";
            return;
        }
        else {
            break;
        }
    }
    bool ok = true;
    for (int i = 0; i < k; i++) {
        if (vp[i].second == f) ok = false;
    }
    if (ok) {
        no;
        return;
    }
    yes;
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
