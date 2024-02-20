// Time:  O(n * l)
// Space: O(t)

// trie
class Solution {
private:
    class Trie {
    public:
        Trie()
         : nodes_() {
             new_node();
         }

        int add(const string& w) {
            int result = 0, curr = 0;
            for (int i = 0; i < size(w); ++i) {
                const int k = (w[i] - 'a') * 26 + (w[size(w) - 1 - i] - 'a');
                if (!nodes_[curr].count(k)) {
                    nodes_[curr][k] = new_node();
                }
                curr = nodes_[curr][k];
                result += cnts_[curr];
            }
            ++cnts_[curr];
            return result;
        }

    private:
        int new_node() {
            nodes_.emplace_back();
            cnts_.emplace_back(0);
            return size(nodes_) - 1;
        }

        vector<unordered_map<int, int>> nodes_;
        vector<int> cnts_;
    };

public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int64_t result = 0;
        Trie trie;
        for (const auto& w : words) {
            result += trie.add(w);
        }
        return result;
    }
};
