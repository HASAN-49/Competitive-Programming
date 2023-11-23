// بسم الله الرحمن الرحيم
// Solution of CodeChef problem Chroma Swap
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

void solve(int tt) 
{
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), ca(n), cb(n);
    vector<multiset<int>> vm(2*n+1);
    map<int, bool> mp;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> ca[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        cin >> cb[i];
        vm[ca[i]].insert(a[i]);
        vm[cb[i]].insert(b[i]);
        mp[cb[i]] = 1;
    }

    bool ok = true;
    int pre = -1;

    for(int i = 0; i < n; i++) {
        if(!mp[ca[i]]) {
            if(a[i] < pre) {
                ok = false;
                break;
            }
            pre = a[i];
            continue;
        }

        int it = *vm[ca[i]].rbegin();
        if(pre > it) {
            ok = false;
            break;
        }

        pre = *vm[ca[i]].lower_bound(pre);
        vm[ca[i]].erase(vm[ca[i]].find(pre));
    }
    if(ok) yes;
    else no;
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
