// Time:  O(n * q)
// Space: O(n)

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result(size(l));
        for (int i = 0; i < size(l); ++i) {
            result[i] = isArith(vector<int>(cbegin(nums) + l[i], cbegin(nums) + r[i] + 1));
        }
        return result;
    }

private:
    bool isArith(const vector<int>& nums) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        int mn = *min_element(cbegin(nums), cend(nums));
        int mx = *max_element(cbegin(nums), cend(nums));
        if (mx == mn) {
            return true;
        }
        if ((mx - mn) % (size(nums) - 1)) {
            return false;
        }
        int d = (mx - mn) / (size(nums) - 1);
        for (int i = mn; i <= mx; i += d) {
            if (!lookup.count(i)) {
                return false;
            }
        }
        return true;
    }
};
