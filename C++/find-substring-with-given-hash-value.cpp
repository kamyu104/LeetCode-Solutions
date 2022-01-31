// Time:  O(n)
// Space: O(1)

// rolling hash
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int idx = 0;
        for (int64_t i = size(s) - 1, pw = 1, h = 0; i >= 0; --i) {
            if ((size(s) - 1) - i + 1 <= k - 1) {
                pw = (pw * power) % modulo;
            } 
            if (i + k < size(s)) {
                h = (h - (s[i + k] - 'a' + 1) * pw % modulo + modulo) % modulo;
            }
            h = (h * power % modulo + (s[i] - 'a' + 1)) % modulo;
            if (h == hashValue) {
                idx = i;
            }
        }        
        return s.substr(idx, k);
    }
};
