// Time:  O(nlogr)
// Space: O(1)

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0.0;
        double right = 1e8;
        while (right - left > 1e-6) {
            const auto mid = left + (right - left) / 2.0;
            if (possible(stations, K, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
    
private:
    bool possible(const vector<int>& stations, int K, double guess) {
        int sum = 0;
        for (int i = 0; i + 1 < stations.size(); ++i) {
            sum += int((stations[i + 1] - stations[i]) / guess);
        }
        return sum <= K;
    }
};
