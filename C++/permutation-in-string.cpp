// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(256);
        for (const auto& c : s1) {
            ++counts[c];
        }
        for (int i = 0, l = s1.length(); i < s2.length(); ++i) {
            if (counts[s2[i]]-- > 0) {
                --l;
            }
            if (l == 0) {
                return true;
            }
            int start = i + 1 - s1.length();
            if (start >= 0 && ++counts[s2[start]] > 0) {
                ++l;
            }
        }
        return false;
    }
};
