// Time:  O(nlogr)
// Space: O(n)

// hash table
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        int result = INF;
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums); ++i) {
            if (lookup.count(nums[i])) {
                result = min(result, i - lookup[nums[i]]);
            }
            lookup[reverse(nums[i])] = i;
        }
        return result != INF ? result : -1;
    }
};
