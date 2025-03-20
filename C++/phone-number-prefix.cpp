// Time:  O(l * nlogn)
// Space: O(1)

// sort
class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(begin(numbers), end(numbers));
        for (int i = 0; i + 1 < size(numbers); ++i) {
            if (numbers[i + 1].starts_with(numbers[i])) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(n * l)
// Space: O(t)
// trie
class Solution2 {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        bool add(const string& s) {
            bool made = false;
            int curr = 0;
            for (int i = 0; i < size(s); ++i) {
                const int x = s[i] - '0';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                    made = true;
                } else if (nodes_[nodes_[curr][x]].back() == 1) {
                    return false;
                }
                curr = nodes_[curr][x];
            }
            nodes_[curr].back() = 1;
            return made;
        }

    private:
        int new_node() {
            nodes_.emplace_back(11, -1);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> cnts_;
    };

public:
    bool phonePrefix(vector<string>& numbers) {
        Trie trie;
        for (const auto& x : numbers) {
            if (!trie.add(x)) {
                return false;
            }
        }
        return true;
    }
};
