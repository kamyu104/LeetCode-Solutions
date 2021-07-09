// Time:  O(n) on average
// Space: O(n)

// reference: https://en.wikipedia.org/wiki/Smallest-circle_problem
class Solution {
public:
    vector<double> outerTrees(vector<vector<int>>& trees) {
        random_shuffle(begin(trees), end(trees));
        vector<vector<double>> boundaries;
        const auto& result = Welzl(trees, &boundaries, 0);
        return {result.first[0], result.first[1], result.second};
    }

private:
    pair<vector<double>, double> Welzl(
        const vector<vector<int>>& points,
        vector<vector<double>> *boundaries,
        int curr) {

        if (curr == size(points) || size(*boundaries) == 3) {
            return trivial(*boundaries);
        }
        vector<double> p = {double(points[curr][0]), double(points[curr][1])};
        const auto& result = Welzl(points, boundaries, curr + 1);
        if (!empty(result.first) && inside(result, p)) {
            return result;
        }
        boundaries->emplace_back(move(p));
        const auto& result2 = Welzl(points, boundaries, curr + 1);
        boundaries->pop_back();
        return result2;
    }

    pair<vector<double>, double> trivial(const vector<vector<double>>& boundaries) {  // circumscribed circle
        if (empty(boundaries)) {
            return {{}, 0.0};
        }
        if (size(boundaries) == 1) {
            return {boundaries[0], 0.0};
        }
        if (size(boundaries) == 2) {
            return circle_from_2_points(boundaries[0], boundaries[1]);
        }
        return circle_from_3_points(boundaries[0], boundaries[1], boundaries[2]);
    }

    double dist(const vector<double>& a, const vector<double>& b) {
        return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }

    bool inside(const pair<vector<double>, double>& c, const vector<double>& p) {
        static const double EPS = 1e-5;
        return dist(c.first, p) < c.second + EPS;
    }

    vector<double> circle_center(int bx, int by, int cx, int cy) {
        double B = bx * bx + by * by;
        double C = cx * cx + cy * cy;
        double D = bx * cy - by * cx;
        return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
    }

    pair<vector<double>, double> circle_from_2_points(
        const vector<double>& A,
        const vector<double>& B) {

        vector<double> C = {(A[0] + B[0]) / 2.0, (A[1] + B[1]) / 2.0};
        return {C, dist(A, B) / 2.0};
    }

    pair<vector<double>, double> circle_from_3_points(
        const vector<double>& A,
        const vector<double>& B,
        const vector<double>& C) {

        vector<double> I = circle_center(B[0] - A[0], B[1] - A[1], C[0] - A[0], C[1] - A[1]);
        I[0] += A[0];
        I[1] += A[1];
        return {I, dist(I, A)};
    }
};
