// Time:  O(nlogn + nlogr) = O(nlogr), r = max(nums)
// Space: O(t)

// bit manipulation, greedy, trie, sort, two pointers
class Solution {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_() {
             new_node();
         }

        void update(int num, int d) {
            int curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int x = num >> i;
                if (nodes_[curr][x & 1] == -1) {
                    nodes_[curr][x & 1] = new_node();
                }
                curr = nodes_[curr][x & 1];
                cnts_[curr] += d;
            }
        }

        int query(int num) {
            int result = 0, curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                result <<= 1;
                const int x = num >> i;
                if (nodes_[curr][1 ^ (x & 1)] != -1 && cnts_[nodes_[curr][1 ^ (x & 1)]]) {
                    result |= 1;
                    curr = nodes_[curr][1 ^ (x & 1)];
                } else {
                    curr = nodes_[curr][x & 1];
                }
            }
            return result;
        }

    private:
        int new_node() {
            nodes_.push_back(array<int, 2>{-1, -1});
            cnts_.emplace_back(0);
            return size(nodes_) - 1;
        }

        const int bit_length_;
        vector<array<int, 2>> nodes_;
        vector<int> cnts_;
    };

public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(begin(nums), end(nums));
        Trie trie(bit_length(nums.back()));
        int result = 0;
        for (int i = 0, j = 0; i < size(nums); ++i) {
            trie.update(nums[i], +1);
            while (!(nums[i] <= 2 * nums[j])) {
                trie.update(nums[j++], -1);
            }
            result = max(result, trie.query(nums[i]));
        }
        return result;
    }

private:
    int bit_length(int x) {
        return (x ? std::__lg(x) : -1) + 1;
    }
};

// Time:  O(nlogr), r = max(nums)
// Space: O(t)
// bit manipulation, greedy, trie, dp
class Solution2 {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_() {
             new_node();
         }

        void insert(int num) {
            int curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int x = num >> i;
                if (nodes_[curr][x & 1] == -1) {
                    nodes_[curr][x & 1] = new_node();
                }
                curr = nodes_[curr][x & 1];
                mins_[curr] = min(mins_[curr], num);
                maxs_[curr] = max(maxs_[curr], num);
            }
        }

        int query(int num) {
            int result = 0, curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                result <<= 1;
                const int x = num >> i;
                const int y = (result | 1) ^ x;
                assert(x != y);
                if (nodes_[curr][y & 1] != -1 && 
                    ((x > y && num <= 2 * maxs_[nodes_[curr][y & 1]]) ||
                     (x < y && mins_[nodes_[curr][y & 1]] <= 2 * num))) {
                    result |= 1;
                    curr = nodes_[curr][y & 1];
                } else {
                    curr = nodes_[curr][(y & 1) ^ 1];
                }
            }
            return result;
        }

    private:
        int new_node() {
            nodes_.push_back(array<int, 2>{-1, -1});
            mins_.emplace_back(numeric_limits<int>::max());
            maxs_.emplace_back(numeric_limits<int>::min());
            return size(nodes_) - 1;
        }

        const int bit_length_;
        vector<array<int, 2>> nodes_;
        vector<int> mins_;
        vector<int> maxs_;
    };

public:
    int maximumStrongPairXor(vector<int>& nums) {
        Trie trie(bit_length(*max_element(cbegin(nums), cend(nums))));
        int result = 0;
        for (const auto& num : nums) {
            trie.insert(num);
            result = max(result, trie.query(num));
        }
        return result;
    }

private:
    int bit_length(int x) {
        return (x ? std::__lg(x) : -1) + 1;
    }
};

// Time:  O(nlogr), r = max(nums)
// Space: O(n)
// bit manipulation, greedy, dp
class Solution3 {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int result = 0;
        for (int i = bit_length(*max_element(cbegin(nums), cend(nums))) - 1; i >= 0; --i) {
            unordered_map<int, int> prefix_min, prefix_max;
            for (const auto& x : nums) {
                const int y = x >> i;
                if (!prefix_min.count(y)) {
                    prefix_min[y] = prefix_max[y] = x;
                }
                prefix_min[y] = min(prefix_min[y], x);
                prefix_max[y] = max(prefix_max[y], x);
            }
            result <<= 1;
            for (const auto& [x, _] : prefix_min) {
                const int y = (result | 1) ^ x;
                assert(x != y);
                if (prefix_max.count(y) && prefix_min[max(x, y)] <= 2 * prefix_max[min(x, y)]) {
                    result |= 1;
                    break;
                }
            }
        }
        return result;
    }

private:
    int bit_length(int x) {
        return (x ? std::__lg(x) : -1) + 1;
    }
};
