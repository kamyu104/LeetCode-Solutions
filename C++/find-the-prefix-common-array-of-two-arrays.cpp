// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result(size(A));
        unordered_map<int, int> cnt;
        for (int i = 0, curr = 0; i < size(result); ++i) {
            if (++cnt[A[i]] == 2) {
                ++curr;
            }
            if (++cnt[B[i]] == 2) {
                ++curr;
            }
            result[i] = curr;
        }
        return result;
    }
};
