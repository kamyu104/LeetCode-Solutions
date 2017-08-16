// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        auto pre = numeric_limits<int>::min(), cur = 0;
        auto cnt1 = 0, cnt2 = 0, cnt3 = 0;  // count of each length ending at cur
        for (int i = 0; i < nums.size(); pre = cur) {
            auto cnt = 0;
            for (cur = nums[i]; i < nums.size() && cur == nums[i]; ++cnt, ++i);

            if (cur != pre + 1) {
                if (cnt1 != 0 || cnt2 != 0) {
                    return false;
                }
                tie(cnt1, cnt2, cnt3) = make_tuple(cnt, 0, 0);
            } else {
                if (cnt < cnt1 + cnt2) {
                    return false;
                }
                tie(cnt1, cnt2, cnt3) = make_tuple(max(0, cnt - (cnt1 + cnt2 + cnt3)),
                                                   cnt1,
                                                   cnt2 + min(cnt3, cnt - (cnt1 + cnt2)));
            }
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};
