// Time:  O(l * n^2)
// Space: O(1)

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),
             [](const string& a, const string& b) { return a.length() > b.length(); });
        for (int i = 0; i < strs.size(); ++i) {
            bool all_of = true;
            for (int j = 0; strs[j].length() >= strs[i].length() && j < strs.size(); ++j) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    all_of = false;
                    break;
                }
            }
            if (all_of) {
                return strs[i].length();
            }
        }
        return -1;
    }

private:
    bool isSubsequence(const string& a, const string& b) {
        int i = 0;
        for (int j = 0; j < b.length() && i < a.length(); ++j) {
            if (a[i] == b[j]) {
                ++i;
            }
        }
        return i == a.length();
    }
};
