// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        for (int j = 0; j < chars.size();) {
            if (j + 1 == chars.size() || chars[j] != chars[j + 1]) {
                chars[i++] = chars[j++];
            } else {
                int k = j;
                while (j < chars.size() && chars[j] == chars[k]) {
                    ++j;
                }
                chars[i++] = chars[k];
                auto n = j - k, prev_i = i;
                while (n > 0) {
                    chars[i++] = n % 10 + '0';
                    n /= 10;
                }
                reverse(chars.begin() + prev_i, chars.begin() + i);
            }
        }
        return i;
    }
};
