// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        for (const auto& num : nums) {
            ++lookup[num];
        }
        int result = 0;
        for (const auto& [num, cnt] : lookup) {
            if (k - num == num) {
                result += cnt / 2;
            } else if (lookup.count(k - num))  {
                int c = min(cnt, lookup[k - num]);
                result += c;
                lookup[num] -= c;
                lookup[k - num] -= c;
            }
        }
        return result;
    }
};
