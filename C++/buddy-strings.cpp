// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        vector<int> diff;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                diff.emplace_back(i);
                if (diff.size() > 2) {
                    return false;
                }
            }
        }
        return (diff.empty() && unordered_set<char>(A.begin(), A.end()).size() < A.size()) ||
               (diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]);
    }
};
