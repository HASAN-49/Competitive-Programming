// بسم الله الرحمن الرحيم
// Solution of Hackerearth Problem (Connected Components in a Graph)
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
#define M 1000000007
#define Mm 998244353

const int N = 1e5*2+1;
vector<int> g[N];
bool visited[N];

void dfs(int vertext) {
    if(visited[vertext]) return;
    visited[vertext] = true;
    for(auto child : g[vertext]){
        dfs(child);
    }
}

void solve(int tt) 
{
    int n, e;
    cin >> n >> e;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        visited[i] = 0;
    }
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
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
