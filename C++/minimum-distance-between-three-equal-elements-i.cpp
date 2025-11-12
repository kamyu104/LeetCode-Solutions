// Time:  O(n)
// Space: O(n)

// hash table, sliding window
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        int result = INF;
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < size(nums); ++i) {
            lookup[nums[i]].emplace_back(i);
            if (size(lookup[nums[i]]) < 3) {
                continue;
            }
            result = min(result, 2 * (i - lookup[nums[i]][size(lookup[nums[i]]) - 3]));  // k, j, i = lookup[x][:-3], (i-j)+(j-k)+(i-k) = 2*(i-k)
        }
        return result != INF ? result : -1;
    }
};
