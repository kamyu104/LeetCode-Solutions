// Time:  O(nlogr)
// Space: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = *max_element(piles.cbegin(), piles.cend());
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (possible(piles, H, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool possible(const vector<int>& piles, int H, int K) {
        int time = 0;
        for (const auto& pile : piles) {
            time += (pile - 1) / K + 1;
        }
        return time <= H;
    }
};
