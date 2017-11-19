// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; ++i) {
            if (isDividingNumber(i)) {
                result.emplace_back(i);
            }
        }
        return result;
    }

private:
    bool isDividingNumber(int num) {
        for (int n = num; n > 0; n /= 10) {
            if (!(n % 10) || num % (n % 10)) {
                return false;
            }
        }
        return true;
    }
};
