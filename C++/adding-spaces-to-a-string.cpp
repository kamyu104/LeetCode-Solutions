// Time:  O(n)
// Space: O(1)

// inplace solution
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int prev = size(s);
        s.resize(size(s) + size(spaces));
        for(int i = size(spaces) - 1; i >= 0; --i) {
            for (int j = prev - 1; j >= spaces[i]; --j) {
                s[j + 1 + i] = s[j];
            }
            s[spaces[i] + i] = ' ';
            prev = spaces[i];
        }
        return s;
    }
};
