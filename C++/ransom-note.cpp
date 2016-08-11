// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counts(26);
        int letters = 0;
        for (const auto& c : ransomNote) {
            if (counts[c - 'a']++ == 0) {
                ++letters;
            }
        }
        for (const auto& c : magazine) {
            if (--counts[c - 'a'] == 0 && --letters == 0) {
                // Break as soon as possible if letters have been enough.
                break;
            }
        }
        return letters == 0;
    }
};
