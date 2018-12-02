// Time:  O(f * n), f is the max number of unique prime factors
// Soace: O(p + n), p is the total number of unique primes

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        UnionFind union_find(A.size());
        unordered_map<int, int> nodesWithCommonFactor;
        for (int i = 0; i < A.size(); ++i) {
            for (const auto& factor : primeFactors(A[i])) {
                if (!nodesWithCommonFactor.count(factor)) {
                    nodesWithCommonFactor[factor] = i;
                }
                union_find.union_set(nodesWithCommonFactor[factor], i);
            }
         }
        return union_find.max_size();
    }

private:
    vector<int> primeFactors(int i) const {
        vector<int> result;
        int d = 2;
        if (i % d == 0) {
            while (i % d == 0) {
                i /= d;
            }
            result.emplace_back(d);
        }
        d = 3;
        for (d = 3; d * d <= i; d += 2) {
            if (i % d == 0) {
                while (i % d == 0) {
                    i /= d;
                }
                result.emplace_back(d);
            }
        }
        if (i > 2) {
            result.emplace_back(i);
        }
        return result;
    }

    class UnionFind {
        public:
            UnionFind(const int n) : set_(n), size_(n, 1) {
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
                size_[max(x_root, y_root)] += size_[min(x_root, y_root)];
                return true;
            }
        
            int max_size() const {
                return *max_element(size_.cbegin(), size_.cend());
            }

        private:
            vector<int> set_;
            vector<int> size_;
    };
};
