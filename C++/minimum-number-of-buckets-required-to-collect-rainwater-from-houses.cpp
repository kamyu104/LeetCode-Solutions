// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minimumBuckets(string street) {
        int result = 0;
        for (int i = 0; i < size(street); ++i) {
            if (street[i] != 'H' || (i && street[i - 1] == 'B')) {
                continue;
            }
            if (i + 1 < size(street) && street[i + 1] == '.') {
                street[i + 1] = 'B';
                ++result;
            } else if (i && street[i - 1] == '.') {
                street[i - 1] = 'B';
                ++result;
            } else {
                return -1;
            }
        }
        return result;
    }
};
