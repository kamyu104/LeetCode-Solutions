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
        while (int size = read4(buffer)) {
            size = min(size, n - read_bytes);
            for (int i = 0; i < size; ++i) {
                buf[read_bytes++] = buffer[i];
            }
        }
        return read_bytes;
    }
};
