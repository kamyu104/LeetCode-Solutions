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

// Time:  O(n^2 * l)
// Space: O(1)
// brute force
class Solution2 {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        const auto& check = [&](int i, int j) {
            return words[j].starts_with(words[i]) && words[j].ends_with(words[i]);
        };

        int64_t result = 0;
        for (int i = 0; i < size(words); ++i) {
            for (int j = i + 1; j < size(words); ++j) {
                if (check(i, j)) {
                    ++result;
                }
            }
        }
        return result;
    }
};
