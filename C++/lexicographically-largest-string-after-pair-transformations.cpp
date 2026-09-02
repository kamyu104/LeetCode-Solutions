// Time:  O(n * (r / 2^25 + 25)) = O(n)
// Space: O(1)

// greedy
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        const auto& f = [](int x) {
            string result(x / (1 << 25), 'z');
            x %= 1 << 25;
            for (int i = 24; i >= 0; --i) {
                if (x & (1 << i)) {
                    result.push_back('a' + i);
                }
            }
            return result;
        };

        vector<string> result;
        result.reserve(size(nums));
        for (const auto& x : nums) {
            result.emplace_back(f(x));
        }
        return result;
    }
};
