// Time:  O((n + q) * l)
// Space: O(t)

// trie
class Solution {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        void add(int i, const string& w) {
            int curr = 0;
            mns_[curr] = min(mns_[curr], {size(w), i});
            for (int j = size(w) - 1; j >= 0; --j) {
                const int x = w[j] - 'a';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
                mns_[curr] = min(mns_[curr], {size(w), i});
            }
        }

        int query(const string& w) {
            int curr = 0;
            for (int j = size(w) - 1; j >= 0; --j) {
                const int x = w[j] - 'a';
                if (nodes_[curr][x] == -1) {
                    break;
                }
                curr = nodes_[curr][x];
            }
            return mns_[curr].second;
        }

    private:
        int new_node() {
            static const int INF = numeric_limits<int>::max();

            nodes_.emplace_back(26, -1);
            mns_.emplace_back(INF, INF);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<pair<int, int>> mns_;
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        for (int i = 0; i < size(wordsContainer); ++i) {
            trie.add(i, wordsContainer[i]);
        }
        vector<int> result(size(wordsQuery));
        for (int i = 0; i < size(wordsQuery); ++i) {
            result[i] = trie.query(wordsQuery[i]);
        }
        return result;
    }
};
