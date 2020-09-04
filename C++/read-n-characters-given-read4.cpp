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
        char buffer[4];
        for (int i = 0; i < (n + 4 - 1) / 4; ++i) {
            int size = min(read4(buffer), n - read_bytes);
            for (int j = 0; j < size; ++j) {
                buf[read_bytes++] = buffer[j];
            }
        }
        return read_bytes;
    }
};
