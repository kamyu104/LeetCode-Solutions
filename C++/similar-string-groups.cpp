// Time:  O(n^2 * l), l is the average length of words
// Space: O(n)

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        UnionFind union_find(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (isSimilar(A[i], A[j])) {
                    union_find.union_set(i, j);
                }
            }
        }
        return union_find.size();
    }
    
private:
    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 2) {
                    return false;
                }
            }
        }
        return diff == 2;
    }
    
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), size_(n) {
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
                --size_;
                return true;
            }
        
            int size() const {
                return size_;
            }

        private:
            vector<int> set_;
            int size_;
    };
};

// Time:  O(n^2 * l) ~ O(n * l^4)
// Space: O(n) ~ O(n * l^3)
class Solution_MLE {
public:
    int numSimilarGroups(vector<string>& A) {
        const int N = A.size(), L = A[0].length();
        UnionFind union_find(A.size());
        if (N < L*L) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (isSimilar(A[i], A[j])) {
                        union_find.union_set(i, j);
                    }
                }
            }
        } else {
            unordered_map<string, vector<int>> buckets;
            unordered_set<string> lookup;
            for (int i = 0; i < A.size(); ++i) {
                auto word = A[i];
                if (!lookup.count(word)) {
                    buckets[word].emplace_back(i);
                    lookup.emplace(word);
                }
                for (int j1 = 0; j1 < L; ++j1) {
                    for (int j2 = 0; j2 < j1; ++j2) {
                        swap(word[j1], word[j2]);
                        buckets[word].emplace_back(i);
                        swap(word[j1], word[j2]);
                    }
                }
            }
            for (const auto& word : A) {
                for (int i = 0; i < buckets[word].size(); ++i) {
                    for (int j = 0; j < i; ++j) {
                        union_find.union_set(buckets[word][i], buckets[word][j]);
                    }
                }
            }
        }
        return union_find.size();
    }
    
private:
    bool isSimilar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                if (++diff > 2) {
                    return false;
                }
            }
        }
        return diff == 2;
    }
    
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), size_(n) {
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
                --size_;
                return true;
            }
        
            int size() const {
                return size_;
            }

        private:
            vector<int> set_;
            int size_;
    };
};
