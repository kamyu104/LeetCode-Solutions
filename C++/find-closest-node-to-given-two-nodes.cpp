// Time:  O(n)
// Space: O(n)

// graph, hash table
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const auto& dfs = [&](int node) {
            unordered_map<int, int> lookup;
            for (int i = 0; node != -1; ++i, node = edges[node]) {
                if (lookup.count(node)) {
                    break;
                }
                lookup[node] = i;
            }
            return lookup;
        };

        const auto& lookup1 = dfs(node1);
        const auto& lookup2 = dfs(node2);
        int result = -1;
        int mn = numeric_limits<int>::max();
        for (const auto& [k, v] : lookup1) {
            if (!lookup2.count(k)) {
                continue;
            }
            const auto& curr = max(lookup1.at(k), lookup2.at(k));
            if (curr < mn) {
                mn = curr;
                result = k;
            } else if (curr == mn) {
                if (k < result) {
                    result = k;
                }
            }
        }
        return result;
    }
};
