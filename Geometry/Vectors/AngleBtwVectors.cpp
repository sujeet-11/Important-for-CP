#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define endl '\n'
#define sp ' '

const ld PI = acosl(-1.0L);
const ld EPS = 1e-12L;

struct Point {
  ld x, y;
  Point(ld x = 0, ld y = 0) : x(x), y(y) {}
  ld dot(Point b) {
    return x * b.x + y * b.y;
  }
  ld length() {
    return sqrtl(x * x + y * y);
  }
  ld angle(Point b) {
    ld lenA = length();
    ld lenB = b.length();
    if (lenA < EPS || lenB < EPS) {
      return -1;
    }
    ld cosine = dot(b) / (lenA * lenB);
    cosine = clamp(cosine, -1.0L, 1.0L);
    return acosl(cosine);
  }
  ld angleDegrees(Point b) {
    ld rad = angle(b);
    if (rad < 0) {
      return -1;
    }
    return rad * 180.0L / PI;
  }
};

void solve() {
  ld x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  Point A(x1, y1);
  Point B(x2, y2);
  ld rad = A.angle(B);
  if (rad < 0) {
    cout << "Undefined" << endl;
    return;
  }
  ld deg = A.angleDegrees(B);
  cout << "Angle in radians: " << rad << endl;
  cout << "Angle in degrees: " << deg << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
