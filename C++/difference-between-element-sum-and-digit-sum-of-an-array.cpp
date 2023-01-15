// Time:  O(nlogr), r = max(nums)
// Space: O(1)

// array
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        const auto& total = [](int x) {
            int result = 0;
            while (x) {
                result += x % 10;
                x /= 10;
            }
            return result;
        };

        return abs(accumulate(cbegin(nums), cend(nums), 0) - 
                   accumulate(cbegin(nums), cend(nums), 0, [&](const auto& accu, const auto& x) {
                       return accu + total(x);
                   }));
    }
};
