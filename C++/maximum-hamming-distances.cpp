// Time:  O(m * 2^m)
// Space: O(2^m)

// bitmasks, bfs
class Solution {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        vector<vector<int>> group(1 << m);
        for (int i = 0; i < size(nums); ++i) {
            group[((1 << m) - 1) ^ nums[i]].emplace_back(i);
        }
        vector<int> result(size(nums));
        vector<int> lookup(1 << m);
        for (const auto& x : nums) {
            lookup[x] = true;
        }
        vector<int> q = move(nums);
        for (int d = 0; !empty(q); ++d) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& i : group[u]) {
                    result[i] = m - d;
                }
                for (int i = 0; i < m; ++i) {
                    if (lookup[u ^ (1 << i)]) {
                        continue;
                    }
                    lookup[u ^ (1 << i)] = true;
                    new_q.emplace_back(u ^ (1 << i));
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
