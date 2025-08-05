// Time:  O(nlogr), r = max(max(nums), k, 1)
// Space: O(t)

// prefix sum, trie
class Solution {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_() {
             new_node();
         }

        void add(int num) {
            int curr = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                const auto& x = (num >> i) & 1;
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
                ++cnts_[curr];
            }
        }

        int query(int prefix, int k) {
            int result = 0, curr = 0;
            for (int i = bit_length_ - 1; i >= 0 && curr != -1; --i) {
                const auto& t = (k >> i) & 1;
                const auto& x = (prefix >> i) & 1;
                if (t == 0) {
                    const auto& tmp = nodes_[curr][1 ^ x];
                    if (tmp != -1) {
                        result += cnts_[tmp];
                    }
                }
                curr = nodes_[curr][t ^ x];
            }
            if (curr != -1) {
                result += cnts_[curr];
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
    long long countXorSubarrays(vector<int>& nums, int k) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        int64_t result = 0;
        int prefix = 0;
        const auto& mx = max({ranges::max(nums), k, 1});
        Trie trie(bit_length(mx));
        trie.add(0);
        for (const auto& x : nums) {
            prefix ^= x;
            result += trie.query(prefix, k);
            trie.add(prefix);
        }
        return result;
    }
};
