// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }

private:
    int count(const vector<int>& A, int bound) const {
        int result = 0, curr = 0;
        for (const auto& i : A) {
            curr = (i <= bound) ? curr + 1 : 0;
            result += curr;
        }
        return result;
    }
};
