// بسم الله الرحمن الرحيم
// Solution of Codeforces Problem 1791F (Range Update Point Query)
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ld long double

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nline cout << "\n"

#define pi 3.14159265358979323846
#define M 1000000007
#define Mm 998244353

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {-1, -1, 1, 1};

void solve(int tt) 
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    set<int> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] >= 10) s.insert(i);
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            int l, r;
            cin >> l >> r;
            int lst = l;
            while(!s.empty()) {
                auto it = s.lower_bound(l);
                int p = *it;
                if(it == s.end() || p > r) break;
                int sum = 0;
                while(a[p] > 0) {
                    sum += (a[p] % 10);
                    a[p] /= 10;
                }
                a[p] = sum;
                if(a[p] < 10) s.erase(p);
                l = p + 1;
            }
        }
        else {
            cin >> x;
            cout << a[x] << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // sieve();
    int k = 1;
    test solve(k++);
    // cout << "HASAN\n";
    return 0;
}
