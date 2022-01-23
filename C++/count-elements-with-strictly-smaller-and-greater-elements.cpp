// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int countElements(vector<int>& nums) {
        const int mn = *min_element(cbegin(nums), cend(nums));
        const int mx = *max_element(cbegin(nums), cend(nums));
        return count_if(cbegin(nums), cend(nums), [&mn, &mx](const auto& x) {
            return mn < x && x < mx;
        });
    }
};
