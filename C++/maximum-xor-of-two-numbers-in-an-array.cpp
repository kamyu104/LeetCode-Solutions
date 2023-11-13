// Time:  O(nlogr), r = max(nums)
// Space: O(t)

class Solution {
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
            }
        }

        int query(int num) {
            int result = 0, curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                result <<= 1;
                const int x = num >> i;
                if (nodes_[curr][1 ^ (x & 1)] != -1) {
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
            return size(nodes_) - 1;
        }

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

// Time:  O(nlogr), r = max(nums)
// Space: O(n)
class Solution2 {
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
