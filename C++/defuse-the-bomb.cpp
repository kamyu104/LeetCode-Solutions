// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(size(code));
        if (k == 0) {
            return result;
        }
        int left = 1, right = k;
        if (k < 0) {
            k = -k;
            left = size(code) - k, right = size(code) - 1;
        }
        int total = accumulate(begin(code) + left, begin(code) + right + 1, 0);
        for (int i = 0; i < size(code); ++i) {
            result[i] = total;
            total -= code[left++ % size(code)];
            total += code[++right % size(code)];
        }
        return result;
    }
};
