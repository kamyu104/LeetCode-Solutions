// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int left = *min_element(sweetness.cbegin(), sweetness.cend());
        int right = accumulate(sweetness.cbegin(), sweetness.cend(), 0) / (K + 1);
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(sweetness, K, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<int>& sweetness, int K, int x) {
        int curr = 0, cuts = 0;
        for (const auto& s : sweetness) {
            curr += s;
            if (curr >= x) {
                ++cuts;
                curr = 0;
            }
        }
        return cuts >= K + 1;
    }
};
