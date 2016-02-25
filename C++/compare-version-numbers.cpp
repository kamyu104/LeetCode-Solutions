// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.length(), n2 = version2.length();
        for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
            int v1 = 0, v2 = 0;
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + version1[i++] - '0';
            }
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + version2[j++] - '0';
            }
            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
        }
        return 0;
    }
};
