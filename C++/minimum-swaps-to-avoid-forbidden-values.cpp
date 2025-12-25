// Time:  O(n)
// Space: O(1)

// boyer-moore majority vote algorithm, greedy
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        const auto& boyer_moore_majority_vote = [&]() {
            int result = 0, cnt = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i] != forbidden[i]) {
                    continue;
                }
                if (cnt == 0) {
                    result = nums[i];
                }
                if (nums[i] == result) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
            return result; 
        };

        const auto& m = boyer_moore_majority_vote();
        int cnt = 0, cnt_m = 0, bal = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != forbidden[i]) {
                if (nums[i] != m  && m != forbidden[i]) {
                    ++bal;
                }
                continue;
            }
            ++cnt;
            if (nums[i] != m) {
                ++bal;
            } else {
                --bal;
                ++cnt_m;
            }
        }
        return bal >= 0 ? max(cnt_m, (cnt + 1) / 2) : -1;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table, greedy
class Solution2 {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int, int> cnt1;
        for (const auto& x : nums) {
            ++cnt1[x];
        }
        unordered_map<int, int> cnt2;
        for (const auto& x : forbidden) {
            ++cnt2[x];
        }
        if (any_of(cbegin(cnt1), cend(cnt1), [&](const auto& x) {
            return x.second +cnt2[x.first] > size(nums);
        })) {
            return -1;
        }
        unordered_map<int, int> cnt3;
        int cnt = 0, cnt_m = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] != forbidden[i]) {
                continue;
            }
            ++cnt;
            cnt_m = max(cnt_m, ++cnt3[nums[i]]);
        }
        return max(cnt_m, (cnt + 1) / 2);
    }
};
