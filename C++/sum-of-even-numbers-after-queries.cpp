// Time:  O(n + q)
// Space: O(1)

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        auto total = accumulate(A.cbegin(), A.cend(), 0,
                                [](int sum, int val) {
                                   return sum + (val % 2 == 0 ? val : 0); 
                                });

        vector<int> result;
        for (const auto& q : queries) {
            int v = q[0], i = q[1];
            if (A[i] % 2 == 0) {
                total -= A[i];
            }
            A[i] += v;
            if (A[i] % 2 == 0) {
                total += A[i];
            }
            result.emplace_back(total);
        }
        return result;
    }
};
