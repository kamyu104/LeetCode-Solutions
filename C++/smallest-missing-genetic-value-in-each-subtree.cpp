// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        vector<int> result(size(parents), 1);
        int i = distance(cbegin(nums), find(cbegin(nums), cend(nums), 1));
        if (i == size(nums)) {
            return result;
        }
        vector<vector<int>> adj(size(parents));
        for (int j = 1; j < size(parents); ++j) {
            adj[parents[j]].emplace_back(j);
        }
        unordered_set<int> lookup;
        for (int miss = 1; i >= 0; i = parents[i]) {
            iter_dfs(adj, nums, i, &lookup);
            for (; lookup.count(miss); ++miss);
            result[i] = miss;
        }
        return result;
    }

private:
    void iter_dfs(const vector<vector<int>>& adj,
                  const vector<int>& nums,
                  int i,
                  unordered_set<int> *lookup) {

        vector<int> stk = {i};
        while (!empty(stk)) {
            i = stk.back(); stk.pop_back();
            if (lookup->count(nums[i])) {
                continue;
            }
            lookup->emplace(nums[i]);
            for (const auto& j : adj[i]) {
                stk.emplace_back(j);
            }
        }
    }
};
