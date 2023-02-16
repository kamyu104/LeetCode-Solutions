// Time:  O(nlogr)
// Space: O(1)

// math
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        return std::transform_reduce(cbegin(nums), cbegin(nums) + size(nums) / 2, rbegin(nums), 0LL, std::plus{},
                                     [](const auto& a, const auto& b) {
                                         return a * pow(10, static_cast<int>(log10(b)) + 1);
                                      }) +
                std::accumulate(cbegin(nums) + size(nums) / 2, cend(nums), 0LL);
    }
};
