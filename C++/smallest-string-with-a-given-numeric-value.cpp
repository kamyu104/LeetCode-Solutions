// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string getSmallestString(int n, int k) {
        static const int MAX_DIFF = 'z' - 'a';
        
        k -= n;
        string result(n, 'a');
        for (int i = n - 1; i >= 0 && k > 0; --i, k -= min(k, MAX_DIFF)) {
            result[i] = 'a' + min(k, MAX_DIFF);
        }
        return result;
    }
};
