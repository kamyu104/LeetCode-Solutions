// Time:  O(l * nlogn)
// Space: O(n)

// sort, sliding window, prefix sum
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string> &words, int k) {
        vector<int> idxs(size(words));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& i, const auto& j) {
            return words[i] < words[j];
        });

        const auto& longest_common_prefix = [&](int k) {
            vector<int> lcp(size(words));
            for (int i = 0; i + (k - 1) < size(words); ++i) {
                const auto& left = words[idxs[i]];
                const auto& right = words[idxs[i + (k - 1)]];
                int j = 0;
                for (; j < min(size(left), size(right)); ++j) {
                    if(left[j] != right[j]) {
                        break;
                    }
                }
                lcp[i] = j;
            }
            return lcp;
        };

        vector<int> lcp = longest_common_prefix(k);
        vector<int> prefix(size(words));
        prefix[0] = lcp[0];
        for(int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = max(prefix[i], lcp[i + 1]);
        }
        vector<int> suffix(size(words));
        suffix[size(words) - 1] = lcp[size(words) - 1];
        for (int i = size(suffix) - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i + 1], lcp[i]);
        }
        vector<int> result(size(words));
        const int mx = ranges::max(longest_common_prefix(k + 1));
        for (int i = 0; i < size(words); i++) {
            const int idx = idxs[i];
            const int mx1 = i - k >= 0 ? prefix[i - k] : 0;
            const int mx2 = i + 1 < size(words) ? suffix[i + 1] : 0;
            result[idx] = max({mx, mx1, mx2});
        }
        return result;
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

        void update(const string& w, int d, int k) {
            int curr = 0;
            vector<int> path(size(w) + 1, -1);
            path[0] = 0;
            for (int i = 0; i < size(w); ++i) {
                const int x = w[i] - 'a';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                path[i + 1] = curr = nodes_[curr][x];
            }
            for (int i = size(path) - 1; i >= 0; --i) {
                const int curr = path[i];
                cnts_[curr] += d;
                mxs_[curr] = cnts_[curr] >= k ? i : 0;
                for (int x = 0; x < 26; ++x) {
                    if (nodes_[curr][x] != -1) {
                        mxs_[curr] = max(mxs_[curr], mxs_[nodes_[curr][x]]);
                    }
                }
            }
        }

        int query() {
            return mxs_[0];
        }

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            cnts_.emplace_back(0);
            mxs_.emplace_back(0);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> cnts_, mxs_;
    };

public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie trie;
        for (const auto& w : words) {
            trie.update(w, +1, k);
        }
        vector<int> result(size(words));
        for (int i = 0; i < size(words); ++i) {
            trie.update(words[i], -1, k);
            result[i] = trie.query();
            trie.update(words[i], +1, k);
        }
        return result;
    }
};
