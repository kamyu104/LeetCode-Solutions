// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, anchor = 0;
        for (int read = 0; read < chars.size(); ++read) {
            if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
                chars[write++] = chars[read];
                if (read - anchor > 0) {
                    auto n = read - anchor + 1, cnt = 0;
                    while (n > 0) {
                        chars[write++] = n % 10 + '0';
                        n /= 10;
                        ++cnt;
                    }
                    reverse(chars.begin() + write - cnt, chars.begin() + write);
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};
