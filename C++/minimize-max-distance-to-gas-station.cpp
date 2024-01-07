// Time:  O(nlogr)
// Space: O(1)

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        const auto& check = [&](double x) {
            int total = 0;
            for (int i = 0; i + 1 < stations.size(); ++i) {
                total += ceil((stations[i + 1] - stations[i]) / x) - 1;
            }
            return total <= K;
        };

        double left = 0.0, right = stations.back() - stations.front();
        while (right - left > 1e-6) {
            const auto mid = left + (right - left) / 2.0;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
