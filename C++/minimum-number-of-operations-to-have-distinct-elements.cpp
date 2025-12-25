// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int minOperations(vector<int>& nums) {
        static const int L = 3;
        const auto ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        unordered_set<int> lookup;
        while (!empty(nums)) {
            if (lookup.count(nums.back())) {
                break;
            }
            lookup.emplace(nums.back());
            nums.pop_back();
        }
        return ceil_divide(size(nums), L);
    }
};
