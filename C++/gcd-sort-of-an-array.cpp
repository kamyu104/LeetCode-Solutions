// Time:  O(nlogn + n * α(n) + m * log(logm)) ~= O(nlogn + m), m is the max of nums
// Space: O(n + m)

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        const int max_num = *max_element(cbegin(nums), cend(nums));
        UnionFind uf(max_num);
        modified_sieve_of_eratosthenes(max_num, unordered_set<int>(cbegin(nums), cend(nums)), &uf);
        vector<int> sorted_nums(cbegin(nums), cend(nums));
        sort(begin(nums), end(nums));
        for (int i = 0; i < size(nums); ++i) {
            if (uf.find_set(nums[i] - 1) != uf.find_set(sorted_nums[i] - 1)) {
                return false;
            }
        }
        return true;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n)
         : set_(n)
         , rank_(n)
         , count_(n) {
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
            if (rank_[x_root] < rank_[y_root]) {  // Union by rank.
                set_[x_root] = y_root;
            } else if (rank_[x_root] > rank_[y_root]) {
                set_[y_root] = x_root;
            } else {
                set_[y_root] = x_root;
                ++rank_[x_root];
            }
            --count_;
            return true;
        }

        int size() const {
            return count_;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        int count_;
    };

    void modified_sieve_of_eratosthenes(int n, const unordered_set<int>& lookup, UnionFind *uf) {  // Time: O(n * log(logn)), Space: O(n)
        if (n < 2) {
            return;
        }
        vector<bool> is_prime(n + 1, true);
        for (int i = 2; i < size(is_prime); ++i) {
            if (!is_prime[i]) {
                continue;
            }
            for (int j = i + i; j < size(is_prime); j += i) {
                is_prime[j] = false;
                if (lookup.count(j)) {  // modified
                    uf->union_set(i - 1, j - 1);
                }
            }
        }
    }
};
