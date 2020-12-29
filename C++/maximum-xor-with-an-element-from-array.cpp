// Time:  O(nlogn + mlogm)
// Space: O(n)

class Trie {
public:
    Trie() : nodes(1) {}
    
    void insert(int num) {
        int idx = 0;
        for (int i = 31; i >= 0; --i) {
            int curr = (num >> i) & 1;
            if (!nodes[idx][curr]) {
                nodes.emplace_back();
                nodes[idx][curr] = size(nodes) - 1;
            }
            idx = nodes[idx][curr];
        }
    }

    int query(int num) {
        if (size(nodes) == 1) {
            return -1;
        }
        int result = 0, idx = 0;
        for (int i = 31; i >= 0; --i) {
            int curr = (num >> i) & 1;
            if (nodes[idx][1 ^ curr]) {
                idx = nodes[idx][1 ^ curr];
                result |= 1 << i;
            } else {
                idx = nodes[idx][curr];
            }
        }
        return result;
    }

private:
    vector<array<int, 2>> nodes;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(nums), end(nums));
        for (int i = 0; i < size(queries); ++i) {
            queries[i].insert(begin(queries[i]), i);
        }
        sort(begin(queries), end(queries),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        vector<int> result(size(queries));
        Trie trie;
        int j = 0;
        for (const auto& q : queries) {
            int i = q[0], x = q[1], m = q[2];
            for (; j < size(nums) && nums[j] <= m; ++j) {
                trie.insert(nums[j]);
            }
            result[i] = trie.query(x);
        }
        return result;
    }
};
