// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        int fi = 0;
        for (int i = 0; i < A.size(); ++i) {
            fi += i * A[i];
        }

        int result = fi;
        for (int i = 1; i <= A.size(); ++i) {
            fi += sum - A.size() * A[A.size() - i];
            result = max(result, fi);
        }
        return result;
    }
};
