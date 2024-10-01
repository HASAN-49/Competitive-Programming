// Problem link --> https://codeforces.com/contest/380/problem/C

// بسم الله الرحمن الرحيم
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
#define M 1e9 + 7;
#define Mm 998244353

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

struct node {
    int left, right, cnt;
};

const int N = 1e6 + 9;
string s;
node t[4 * N];

node merge(node l, node r) {
    node ans;
    int tmp = min(l.left, r.right);
    ans.cnt = l.cnt + r.cnt + 2 * tmp;
    ans.left = l.left + r.left - tmp;
    ans.right = r.right + l.right - tmp;
    return ans;
}

void build(int n, int b, int e) {
    if (b == e) {
        t[n].cnt = 0;
        t[n].left = 0;
        t[n].right = 0;
        if (s[b] == ')') t[n].right = 1;
        if (s[b] == '(') t[n].left = 1;
        return;
    }
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0, 0, 0};
    if (b >= i && e <= j) return t[n];
    int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int tc) {
    cin >> s;
    s = '.' + s;
    int n = s.size();
    int q; cin >> q;
    build(1, 1, n);
    while (q--) {
        int l, r; cin >> l >> r;
        auto ans = query(1, 1, n, l, r);
        cout << ans.cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
