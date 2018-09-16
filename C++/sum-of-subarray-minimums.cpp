// Time:  O(n)
// Space: O(n)

// Ascending stack solution
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        static const int M = 1e9 + 7;

        vector<int> left(A.size());
        stack<pair<int, int>> s1;
        for (int i = 0; i < A.size(); ++i) {
            int count = 1;
            while (!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.emplace(A[i], count);
            left[i] = count;
        }

        vector<int> right(A.size());
        stack<pair<int, int>> s2;
        for (int i = A.size() - 1; i >= 0; --i) {
            int count = 1;
            while (!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.emplace(A[i], count);
            right[i] = count;
        }

        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            result = (result + A[i] * left[i] * right[i]) % M;
        }
        return result;
    }
};
