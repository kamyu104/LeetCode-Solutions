// Time:  O(n)
// Space: O(1)

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int read_bytes = 0;
        for (int i = 0; i <= n / 4; ++i) {
            if (int size = read4(buf + read_bytes)) {
                read_bytes += size;
            } else {
                break;
            }
        }
        return min(read_bytes, n);
    }
};
