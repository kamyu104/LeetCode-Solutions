// Time:  O((logn)^2)
// Space: O(logn)

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> count = counter(N);
        for (int i = 0; i < 31; ++i) {
            if (count == counter(1 << i)) {
                return true;
            }
        }
        return false;
    }

private:
    vector<int> counter(int N) {
        vector<int> result(10, 0);
        for (; N; N /= 10) {
            ++result[N % 10];
        }
        return result;
    }
};
