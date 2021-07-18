// Time:  O(nlogn + mlogm + nlogk + mlogk), k is max(max(nums), max(xi))
// Space: O(nlogk)

class Trie {
public:
    Trie(int bit_length)
     : bit_length_(bit_length)
     , nodes_(1) {}
    
    void insert(int num) {
        int idx = 0;
        for (int i = bit_length_; i >= 0; --i) {
            int curr = (num >> i) & 1;
            if (!nodes_[idx][curr]) {
                nodes_.emplace_back();
                nodes_[idx][curr] = size(nodes_) - 1;
            }
            idx = nodes_[idx][curr];
        }
    }

    int query(int num) {
        if (size(nodes_) == 1) {
            return -1;
        }
        int result = 0, idx = 0;
        for (int i = bit_length_; i >= 0; --i) {
            int curr = (num >> i) & 1;
            if (nodes_[idx][1 ^ curr]) {
                idx = nodes_[idx][1 ^ curr];
                result |= 1 << i;
            } else {
                idx = nodes_[idx][curr];
            }
        }
        return result;
    }

private:
    const int bit_length_;
    vector<array<int, 2>> nodes_;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(nums), end(nums));
        int max_val = max(nums.back(),
                          (*max_element(cbegin(queries), cend(queries),
                                        [](const auto& a, const auto& b) {
                                            return a[0] < b[0];
                                        }))[0]);
        for (int i = 0; i < size(queries); ++i) {
            queries[i].insert(begin(queries[i]), i);
        }
        sort(begin(queries), end(queries),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        vector<int> result(size(queries));
        Trie trie(bit_length(max_val));
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

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
