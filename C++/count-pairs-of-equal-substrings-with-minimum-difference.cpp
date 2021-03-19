// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        vector<int> lookup1(26, -1);
        for (int j = size(firstString) - 1; j >= 0; --j) {
            lookup1[firstString[j] - 'a'] = j;
        }
        vector<int> lookup2(26, -1);
        for (int a = 0; a < size(secondString); ++a) {
            lookup2[secondString[a] - 'a'] = a;
        }
        int result = 0, diff = numeric_limits<int>::max();
        for (int i = 0; i < 26; ++i) {
            if (lookup1[i] == -1 || lookup2[i] == -1) {
                continue;
            }
            if (lookup1[i] - lookup2[i] < diff) {
                diff = lookup1[i] - lookup2[i];
                result = 0;
            }                
            result += (lookup1[i] - lookup2[i] == diff);                
        }
        return result;
    }
};
