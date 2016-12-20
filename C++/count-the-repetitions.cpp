// Time:  O(s1 * n1)
// Space: O(s2)

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(s2.size() + 1, 0);
        unordered_map<int, int> lookup;
        int j = 0, count = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    j = (j + 1) % s2.size();
                    count += (j == 0);
                }
            }
            
            if (lookup.find(j) != lookup.end()) {  // cyclic
                int i = lookup[j];
                int prefixCount = repeatCount[i];
                int patternCount = (count - repeatCount[i]) * ((n1 - i) / (k - i));
                int suffixCount = repeatCount[i + (n1 - i) % (k - i)] - repeatCount[i];
                return (prefixCount + patternCount + suffixCount) / n2;
            }
            lookup[j] = k;
            repeatCount[k] = count;
        }
        return repeatCount[n1] / n2;  // not cyclic iff n1 <= s2
    }
};
