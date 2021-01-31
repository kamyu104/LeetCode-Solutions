// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<int64_t> prefix(size(candiesCount) + 1);
        for (int i = 0; i < size(candiesCount); ++i) {
            prefix[i + 1] = prefix[i] + candiesCount[i];
        }
        vector<bool> result;
        for (const auto& q : queries) {
            result.emplace_back(prefix[q[0]] / q[2] < q[1] + 1 && q[1] + 1 <= prefix[q[0] + 1] / 1);
        }
        return result;
    }
};
