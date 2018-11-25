// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        A.emplace_back(numeric_limits<int>::max());
        int result = 0, duplicate = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i - 1] == A[i]) {
                ++duplicate;
                result -= A[i];
            } else {
                int move = min(duplicate, A[i] - A[i - 1] - 1);
                duplicate -= move;
                result += move * A[i - 1] + move * (move + 1) / 2;
            }
        }
        return result;
    }
};
