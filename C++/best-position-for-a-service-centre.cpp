// Time:  O(n * iter), iter is the number of iterations
// Space: O(1)

// see reference:
// - https://en.wikipedia.org/wiki/Geometric_median
// - https://wikimedia.org/api/rest_v1/media/math/render/svg/b3fb215363358f12687100710caff0e86cd9d26b
// Weiszfeld's algorithm
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        static const double EPS = 1e-6;
        pair<double, double> median;
        median.first = (accumulate(cbegin(positions), cend(positions), 0.0,
                                   [](const auto& a, const auto& b) {
                                       return a + b[0];
                                   }) / positions.size());
        median.second = (accumulate(cbegin(positions), cend(positions), 0.0,
                                    [](const auto& a, const auto& b) {
                                        return a + b[1];
                                    }) / positions.size());
        pair<double, double> prev_median = {-1.0, -1.0};
        while (prev_median.first < 0 || norm(median, prev_median) * positions.size() > EPS) {
            const auto& [stopped, new_median] = geometry_median(positions, median);
            if (stopped) {
                break;
            }
            prev_median = median;
            median = new_median;
        }
        return accumulate(cbegin(positions), cend(positions), 0.0,
                          [this, &median](const auto& a, const auto& b) {
                              return a + norm(median, pair(b[0], b[1]));
                          });
    }

private:
    double norm(const pair<double, double>& p1,
                const pair<double, double>& p2) {
        return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                    (p1.second - p2.second) * (p1.second - p2.second));
    }
        
    pair<bool, pair<double, double>> geometry_median(
        const vector<vector<int>>& positions,
        const pair<double, double>& median) {
        pair<double, double> numerator = {0.0, 0.0};
        double denominator = 0.0;
        for (const auto& p : positions) {
            const auto& l = norm(median, pair(p[0], p[1]));
            if (!l) {
                continue;
            }
            numerator.first += p[0] / l;
            numerator.second += p[1] / l;
            denominator += 1 / l;
        }
        if (denominator == 0.0) {
            return {true, {0.0, 0.0}}; 
        }
        return {false, {numerator.first / denominator, numerator.second / denominator}};
    }
};

// Time:  O(n * iter), iter is the number of iterations
// Space: O(1)
class Solution2 {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        static const double EPS = 1e-6;
        static const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<double, double> median;
        median.first = (accumulate(cbegin(positions), cend(positions), 0.0,
                                   [](const auto& a, const auto& b) {
                                       return a + b[0];
                                    }) / positions.size());
        median.second = (accumulate(cbegin(positions), cend(positions), 0.0,
                                    [](const auto& a, const auto& b) {
                                        return a + b[1];
                                     }) / positions.size());
        double result = dist(positions, median);
        double delta = max((*max_element(cbegin(positions), cend(positions),
                                         [](const auto& x, const auto& y) { return x[0] < y[0]; }))[0],
                           (*max_element(cbegin(positions), cend(positions),
                                         [](const auto& x, const auto& y) { return x[1] < y[1]; }))[1]) -
                       min((*min_element(cbegin(positions), cend(positions),
                                         [](const auto& x, const auto& y) { return x[0] < y[0]; }))[0],
                           (*min_element(cbegin(positions), cend(positions),
                                         [](const auto& x, const auto& y) { return x[1] < y[1]; }))[1]);
        while (delta > EPS) {
            bool found = false;
            for (const auto& [dx, dy] : DIRECTIONS) {
                pair<double, double> new_median = {median.first + delta * dx, median.second + delta * dy};
                const auto& nd = dist(positions, new_median);
                if (nd < result) {
                    result = nd;
                    median = new_median;
                    found = true;
                    break;
                }
            }
            if (!found) {
                delta /= 2.0;
            }
        }
        return result ;
    }

private:
    double dist(const vector<vector<int>>& positions,
                const pair<double, double>& p) {
        return accumulate(cbegin(positions), cend(positions), 0.0,
                          [&p](const auto& a, const auto& b) {
                              return a + sqrt((p.first - b[0]) * (p.first - b[0]) +
                                              (p.second - b[1]) * (p.second - b[1]));
                          });
    }
};
