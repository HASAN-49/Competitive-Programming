// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

struct Point {
  long long x, y;
  Point(long long _x, long long _y) : x(_x), y(_y) {}
};

int orientation(Point p, Point q, Point r) {
  long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; // collinear
  return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

vector<Point> convexHull(vector<Point>& points) {
  int n = points.size();
  if (n < 3) return {}; 

  sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
      return p1.y < p2.y;
    return p1.x < p2.x;
  });

  vector<Point> lower;
  for (int i = 0; i < n; i++) {
    while (lower.size() >= 2 && orientation(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) != 2) {
      lower.pop_back();
    }
    lower.push_back(points[i]);
  }

  vector<Point> upper;
  for (int i = n - 1; i >= 0; i--) {
    while (upper.size() >= 2 && orientation(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) != 2) {
      upper.pop_back();
    }
    upper.push_back(points[i]);
  }

  lower.pop_back();
  upper.pop_back();

  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

void solve() {
  int n; cin >> n;
  vector<Point> points;
  for (int i = 0; i < n; i++) {
    long long x, y; cin >> x >> y;
    points.push_back(Point(x, y));
  }
  vector<Point> hull = convexHull(points);
  int m = hull.size();
  vector<Point> tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)  {
      int k = (j + 1) % m;
      if (hull[j].x == points[i].x && hull[j].y == points[i].y) break;
      if (hull[k].x == points[i].x && hull[k].y == points[i].y) break;
      if (orientation(hull[j], hull[k], points[i]) == 0) {
        if (min(hull[j].x, hull[k].x) <= points[i].x && max(hull[j].x, hull[k].x) >= points[i].x && min(hull[j].y, hull[k].y) <= points[i].y && max(hull[j].y, hull[k].y) >= points[i].y) {
          tmp.push_back(points[i]);
        }
      }
    }
  }
  cout << hull.size() + tmp.size() << '\n';
  for (const Point& p : hull) {
    cout << p.x << ' ' << p.y << endl;
  }
  for (const Point& p : tmp) {
    cout << p.x << ' ' << p.y << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
