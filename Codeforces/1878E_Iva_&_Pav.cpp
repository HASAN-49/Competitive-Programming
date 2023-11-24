// بسم الله الرحمن الرحيم
// Solution of Codeforces 1878E (Iva & Pav)
#include<bits/stdc++.h>
using namespace std ;

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
#define MOD 1000000007

const int N = 200001;
int sum[N][30];
int a[N];

void prefix(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 30; j++) {
            sum[i+1][j] = sum[i][j];
            if(a[i]&(1<<j)) sum[i+1][j] += 1;
        }
    }
}

void solve(int tt) 
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix(n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r = n, k, mid, ans = -1;
        cin >> l >> k;
        int ip = l-1;
        if(a[l-1] < k) {
            cout << ans << " ";
            continue;
        }
        while(l <= r) {
            mid = (l + r) / 2;
            int m = 0;
            for(int j = 0; j < 30; j++) {
                if(sum[mid][j] - sum[ip][j] == mid - ip) m += (1 << j);
            }
            if(m >= k) {
                l = mid + 1;
                ans = max(ans, mid);
            }
            else r = mid -1;
        }
        cout << ans << " ";
    }
    cout << endl;
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
