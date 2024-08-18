/**
 *    author:  dinhviethuy
 *    created: 
**/

#include <bits/stdc++.h>
using namespace std;
#define faster() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define name "dinhviethuy"
#define fi first
#define se second
#define inf 1e9
#define INF 1e18
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
#define pb push_back
#define endl "\n"
#define all(v) v.begin(), v.end()
#define MOD (int)(1e9 + 7)

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool isInside(Point p, Point center, double radius) {
    return distance(p, center) < radius;
}

Point getCircleCenter(Point a, Point b, Point c) {
    double A = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    double Bx = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / (2 * A);
    double By = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / (2 * A);
    return {Bx, By};
}

double getCircleRadius(Point center, Point a) {
    return distance(center, a);
}

void solve() {
    int N, K;
    cin >> N >> K;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    bool found = false;

    for(int i = 0; i < N && !found; i++) {
        for(int j = i + 1; j < N && !found; j++) {
            for(int k = j + 1; k < N && !found; k++) {
                Point a = points[i], b = points[j], c = points[k];
                if((b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x)) {
                    continue;
                }
                Point center = getCircleCenter(a, b, c);
                double radius = getCircleRadius(center, a);
                int cnt = 0;
                for(int m = 0; m < N; ++m) {
                    if(m != i && m != j && m != k && isInside(points[m], center, radius)) {
                        cnt++;
                    }
                }
                if(cnt == K) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(found)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}
 
signed main() {
    // freopen(name".inp", "r", stdin); 
    // freopen(name".out", "w", stdout);
    faster();
    //input
    int t; cin >> t;
    while (t--) 
        solve();
}