// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string stringHash(string s, int k) {
        string result(size(s) / k, 'a');
        for (int i = 0; i < size(s); i += k) {
            int curr = 0;
            for (int j = 0; j < k; ++j) {
                curr = (curr + (s[i + j] - 'a')) % 26;
            }
            result[i / k] += curr;
        }
        return result;   
    }
};
