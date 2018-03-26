// Time:  O(n^4)
// Space: O(n^3)

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        const int n = A.size();
        const int sum = accumulate(A.cbegin(), A.cend(), 0);
        if (!possible(n, sum)) {
            return false;
        }
        
        vector<unordered_set<int>> sums(n / 2 + 1);
        sums[0].emplace(0);
        for (const auto& num: A) {                      // O(n) times
            for (int i = n / 2; i >= 1; --i) {          // O(n) times
                for (const auto& prev : sums[i - 1]) {  // O(1) + O(2) + ... O(n/2) = O(n^2) times
                    sums[i].emplace(prev + num);
                }
            }
        }
        for (int i = 1; i <= n / 2; ++i) {
            if (sum * i % n == 0 &&
                sums[i].count(sum * i / n)) {
                return true;
            }
        }
        return false;
    }

private:
    bool possible(int n, int sum) {
        for (int i = 1; i <= n / 2; ++i)  {
            if (sum * i % n == 0) {
                return true;
            }
        }
        return false;
    }
};
