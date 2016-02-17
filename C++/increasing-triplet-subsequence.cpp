// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = numeric_limits<int>::max(), a = numeric_limits<int>::max(), b = numeric_limits<int>::max();
        for (const auto& c : nums) {
            if (min >= c) {
                min = c;
            } else if (b >= c) {
                a = min, b = c;
            } else {  // a < b < c
                return true;
            }
        }
        return false;
    }
};

// Time:  O(n * logk)
// Space: O(k)
// Generalization of k-uplet.
class Solution_Generalization {
public:
    bool increasingTriplet(vector<int>& nums) {
        return increasingKUplet(nums, 3);
    }

private:
    bool increasingKUplet(const vector<int>& nums, const size_t k) {
        vector<int> inc(k - 1, numeric_limits<int>::max());
        for (const auto& num : nums) {
            auto it = lower_bound(inc.begin(), inc.end(), num);
            if (distance(inc.begin(), it) >= k - 1) {
                return true;
            }
            *it = num;
        }
        return k == 0;
    }
};
