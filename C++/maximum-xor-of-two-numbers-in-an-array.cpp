// Time:  O(nlogk), k is max(nums)
// Space: O(n)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        
        for (int i = bit_length(*max_element(cbegin(nums), cend(nums))) - 1; i >= 0; --i) {
            result <<= 1;
            unordered_set<int> prefixes;
            for (const auto& n : nums) {
                prefixes.emplace(n >> i);
            }
            for (const auto& p : prefixes) {
                if (prefixes.count((result | 1) ^ p)) {
                    result |= 1;
                    break;
                }
            }
        }

        return result;
    }

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};


// Time:  O(nlogk), k is max(nums)
// Space: O(nlogk)
class Solution2 {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_(1) {}

        void insert(int num) {
            int idx = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
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
            for (int i = bit_length_ - 1; i >= 0; --i) {
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

public:
    int findMaximumXOR(vector<int>& nums) {
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
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
