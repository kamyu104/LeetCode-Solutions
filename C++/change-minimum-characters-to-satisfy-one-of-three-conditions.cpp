// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> count1(26), count2(26);
        for (const auto& c : a) {
            ++count1[c - 'a'];
        }
        for (const auto& c : b) {
            ++count2[c - 'a'];
        }
        int result = size(a) + size(b);
        for (int i = 0; i < 26; ++i) {
            result = min(result, int(size(a)) + int(size(b)) - count1[i] - count2[i]);  // condition 3
            if (i > 0) {
                count1[i] += count1[i - 1];
                count2[i] += count2[i - 1];
            }
            if (i < 25) {
                result = min(result, int(size(a)) - count1[i] + count2[i]);  // condition 1
                result = min(result, int(size(b)) - count2[i] + count1[i]);  // condition 2
            }
        }
        return result;
    }
};
