// Time:  O(n)
// Space: O(n)

// line sweep
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> events(size(s) + 1);
        for (const auto& shift : shifts) {
            events[shift[0]] += shift[2] ? 1 : -1;
            events[shift[1] + 1] -= shift[2] ? 1 : -1;
        }
        for (int i = 0, curr = 0; i < size(s); ++i) {
            curr += events[i];
            s[i] = 'a' + ((s[i] - 'a' + curr) % 26 + 26) % 26;
        }
        return s;
    }
};
