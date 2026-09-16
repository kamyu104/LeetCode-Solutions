// Time:  O(n + r * d), r = max(nums), d = len(set(nums))
// Space: O(r + d)

// bfs
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int total = 0;
        for (const auto& x : nums) {
            total ^= x;
        }
        if (total == 0) {
            return 0;
        }
        unordered_set<int> nums_set(cbegin(nums), cend(nums));
        if (size(nums_set) == 1) {
            return -1;
        }
        vector<int> dist(1 << std::bit_width<uint32_t>(ranges::max(nums)), -1);
        dist[0] = 0;
        vector<int> q = {0};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                if (u == total) {
                    return dist[u] != size(nums) ? dist[u] : -1;
                }
                for (const auto& v : nums_set) {
                    if (dist[u ^ v] != -1) {
                        continue;
                    }
                    dist[u ^ v] = dist[u] + 1;
                    new_q.emplace_back(u ^ v);
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
