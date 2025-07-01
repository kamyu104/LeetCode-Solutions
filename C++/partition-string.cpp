// Time:  O(n)
// Space: O(t)

// simulation, trie
class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> result;
        Trie trie;
        string curr;
        for (const auto& c : s) {
            curr.push_back(c);
            trie.add(c);
            if (trie.curr()) {
                continue;
            }
            result.emplace_back(move(curr));
        }
        return result;
    }

private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        void add(int c) {
            const auto& x = c - 'a';
            if (nodes_[curr_][x] == -1) {
                nodes_[curr_][x] = new_node();
                curr_ = 0;
                return;
            }
            curr_ = nodes_[curr_][x];
        }

        int curr() const {
            return curr_;
       }

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        int curr_ = 0;
    };
};
