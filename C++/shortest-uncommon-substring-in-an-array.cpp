// Time:  O(n * l^2)
// Space: O(t)

// trie
class Solution {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        void add(const string& s, int d) {
            for (int i = 0; i < size(s); ++i) {
                int curr = 0;
                for (int j = i; j < size(s); ++j) {
                    const int x = s[j] - 'a';
                    if (nodes_[curr][x] == -1) {
                        nodes_[curr][x] = new_node();
                    }
                    curr = nodes_[curr][x];
                    cnts_[curr] += d;
                }
            }
        }

        string query(const string& s) {
            pair<int, string> result = {numeric_limits<int>::max(), ""};
            for (int i = 0; i < size(s); ++i) {
                int curr = 0;
                for (int j = i; j < size(s); ++j) {
                    const int x = s[j] - 'a';
                    curr = nodes_[curr][x];
                    if (cnts_[curr] == 0) {
                        result = min(result, {j - i + 1, s.substr(i, j - i + 1)});
                        break;
                    }
                }
            }
            return result.second;
        }

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            cnts_.emplace_back(0);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> cnts_;
    };

public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        Trie trie;
        for (const auto& x : arr) {
            trie.add(x, +1);
        }
        vector<string> result;
        for (const auto& x: arr) {
            trie.add(x, -1);
            result.emplace_back(trie.query(x));
            trie.add(x, +1);
        }
        return result;
    }
};
