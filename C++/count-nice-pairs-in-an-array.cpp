// Time:  O(nlogm), m is max of nums
// Space: O(n)

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> lookup;
        int result = 0;
        for (const auto& i : nums) {
            result = (result + lookup[i - rev(i)]++) % MOD;
        }
        return result;
    }

private:
    int rev(int i) {
        int result = 0;
        for (; i; i /= 10) {
            result = result * 10 + i % 10;
        }
        return result;
    }
};
