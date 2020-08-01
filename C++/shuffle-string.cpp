// Time:  O(n)
// Space: O(1)

// in-place solution
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] < 0) {
                continue;
            }
            char move = -s[i];
            for (int j = indices[i]; j != i ; j = indices[j]) {
                swap(s[j], move);
                move = -move;
            }
            s[i] = move;
        }
        for (auto& c : s) {
            c = - c;
        }
        return s;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s.length(), 0);
        for (int i = 0; i < s.length(); ++i) {
            result[indices[i]] = s[i];
        }
        return result;
    }
};
