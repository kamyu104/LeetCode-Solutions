// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int bitwiseComplement(int N) {
        int X = 1;
        while (N > X) {
            X = X * 2 + 1;
        }
        return X - N;
    }
};
