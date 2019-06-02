// Time:  O(nlog*n) ~= O(n), n is the length of S
// Space: O(n)

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        UnionFind union_find(26);
        for (int i = 0; i < A.length(); ++i) {
            union_find.union_set(A[i] - 'a', B[i] - 'a');
        }
        string result;
        for (int i = 0; i < S.length(); ++i) {
            const auto& parent = union_find.find_set(S[i] - 'a');
            result.push_back(parent + 'a');
        }
        return result;
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

        void union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root != y_root) {
                set_[max(x_root, y_root)] = min(x_root, y_root);
            }
        }

    private:
        vector<int> set_;
    };
};
