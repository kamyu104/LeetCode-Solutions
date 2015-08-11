// Time:  O(nlogn) = logn * n^(1/2) * n^(1/4) * ... * 1
// Space: O(logn)

// DFS solution.
class Solution {
    public:
        vector<vector<int>> getFactors(int n) {
            vector<vector<int>> result;
            vector<int> factors;
            getResult(n, &result, &factors);
            return result;
        }

        void getResult(const int n, vector<vector<int>> *result, vector<int> *factors) {
            for (int i = factors->empty() ? 2 : factors->back(); i <= n / i; ++i) {
                if (n % i == 0) {
                    factors->emplace_back(i);
                    factors->emplace_back(n / i);
                    result->emplace_back(*factors);
                    factors->pop_back();
                    getResult(n / i, result, factors);
                    factors->pop_back();
                }
            }
        }
    };
