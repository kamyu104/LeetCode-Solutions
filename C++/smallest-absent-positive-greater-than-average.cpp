// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        const auto& floor_divide = [](int a, int b) {
            const int q = a / b, r = a % b; 
            return q - (r && (a > 0) != (b > 0) ? 1 : 0);
        };

        const auto& total = accumulate(cbegin(nums), cend(nums), 0);
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        int i = max(floor_divide(total, size(nums)) + 1, 1);
        for (; i <= max(ranges::max(nums) + 1, 1); ++i) {
            if (!lookup.count(i) && static_cast<int>(size(nums)) * i > total) {
                break;
            }
        }
        return i;
    }
};
