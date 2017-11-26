// Time:  O(n + p)
// Space: O(p)

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_map<string, int> lookup;
        UnionFind union_find(2 * pairs.size());
        for (const auto& pair : pairs) {
            if (!lookup.count(pair.first)) {
                lookup[pair.first] = lookup.size() - 1;
            }
            if (!lookup.count(pair.second)) {
                lookup[pair.second] = lookup.size() - 1;
            }
            union_find.union_set(lookup[pair.first], lookup[pair.second]);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] != words2[i] && 
                (!lookup.count(words1[i]) || !lookup.count(words2[i]) ||
                union_find.find_set(lookup[words1[i]]) != 
                union_find.find_set(lookup[words2[i]]))) {
                return false;
            }
        }
        return true;
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                return true;
            }

        private:
            vector<int> set_;
    };
};
