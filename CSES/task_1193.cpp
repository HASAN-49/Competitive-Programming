// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1005;
bool vis[N][N], ok;
int n, m, dis[N][N];
pair<int, int> par[N][N];
string s[N], ans;

bool is_ok(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
  // return;
  cin >> n >> m;
  int ai = 0, aj = 0, bi = 0, bj = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'A') ai = i, aj = j;
      if (s[i][j] == 'B') bi = i, bj = j;
    }
  }
  memset(dis, -1, sizeof dis);
  queue<pair<int, int>> q;
  q.push({ai, aj}); vis[ai][aj] = true; dis[ai][aj] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int x = u.first + dx[k];
      int y = u.second + dy[k];
      if (is_ok(x, y) && !vis[x][y] && s[x][y] != '#') {
        q.push({x, y});
        par[x][y] = {u.first, u.second};
        dis[x][y] = dis[u.first][u.second] + 1;
        vis[x][y] = true;
      }
    }
  }
  if (dis[bi][bj] == -1) {
    cout << "NO\n";
    return;
  }
  while (1) {
    // return;
    auto pre = par[bi][bj];
    int x = pre.first - bi;
    int y = pre.second - bj;
    if (x == -1 && y == 0) ans += 'D';
    else if (x == 1 && y == 0) ans += 'U';
    else if (x == 0 && y == 1) ans += 'L';
    else ans += 'R';
    bi = pre.first;
    bj = pre.second;
    if (bi == ai && bj == aj) break;
  }
  cout << "YES\n";
  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
