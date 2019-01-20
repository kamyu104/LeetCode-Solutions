// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        static const auto& cmp = [](int a, int b) {
            return a != b ? (a < b ? 1 : -1) : 0;
        };

        int result = 1;
        int start = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (i == A.size() - 1 ||
               cmp(A[i - 1], A[i]) * cmp(A[i], A[i + 1]) != -1) {
                result = max(result, i - start + 1);
                start = i;
            }
        }
        return result;
    }
};
