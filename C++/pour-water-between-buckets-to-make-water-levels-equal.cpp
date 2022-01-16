// Time:  O(nlogr)
// Space: O(1)

// binary search
class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) {
        static const double EPS = 1e-5;
        double rate = (100.0 - loss) / 100.0;
        auto check = [&buckets, &rate](double x) {
            double extra = 0.0, need = 0.0;
            for (const auto& b : buckets) {
                if (b >= x) {
                    extra += b - x;
                } else {
                    need += x - b;
                }
            }
            return extra * rate >= need;
        };
        double left = *min_element(cbegin(buckets), cend(buckets));
        double right = static_cast<double>(accumulate(cbegin(buckets), cend(buckets), 0ll)) / size(buckets);
        while (right - left > EPS) {
            double mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
