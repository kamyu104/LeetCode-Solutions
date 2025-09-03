#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xs, ys;
        for (auto &p : points) { xs.push_back(p[0]); ys.push_back(p[1]); }
        sort(xs.begin(), xs.end()); xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());
        int nx = xs.size(), ny = ys.size();
        unordered_map<int,int> mp_x, mp_y;
        for (int i = 0; i < nx; ++i) mp_x[xs[i]] = i;
        for (int i = 0; i < ny; ++i) mp_y[ys[i]] = i;
        vector<pair<int,int>> comp_points(n);
        vector<vector<int>> grid(nx, vector<int>(ny, 0));
        for (int i = 0; i < n; ++i) {
            int xi = mp_x[points[i][0]];
            int yi = mp_y[points[i][1]];
            comp_points[i] = {xi, yi};
            grid[xi][yi] = 1;
        }
        vector<vector<int>> ps(nx + 1, vector<int>(ny + 1, 0));
        for (int i = 0; i < nx; ++i)
            for (int j = 0; j < ny; ++j)
                ps[i+1][j+1] = grid[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
        auto rect_sum = [&](int x1, int y1, int x2, int y2) {
            return ps[x2+1][y2+1] - ps[x1][y2+1] - ps[x2+1][y1] + ps[x1][y1];
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int xa = comp_points[i].first, ya = comp_points[i].second;
                int xb = comp_points[j].first, yb = comp_points[j].second;
                if (xa <= xb && ya >= yb) {
                    if (rect_sum(xa, yb, xb, ya) == 2) ++ans;
                }
            }
        }
        return ans;
    }
};
