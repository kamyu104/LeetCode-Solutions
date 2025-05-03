// Time:  O(logn)
// Space: O(1)

// bit manipulation, math
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const auto& bit_length = [](int64_t x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int n = size(nums);
        return n >= 3 ? 1 << bit_length(n) : n;
    }
};
