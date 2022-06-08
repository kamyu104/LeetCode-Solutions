// Time:  O(n)
// Space: O(n)

// simulation, optimized from solution2
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for (int n = size(nums); n != 1; n /= 2) {
            for (int i = 0; i < n / 2; ++i) {
                nums[i] = (i % 2 == 0 ? min(nums[2 * i], nums[2 * i + 1]) : max(nums[2 * i], nums[2 * i + 1]));
            }
        }
        return nums[0];
    }
};

// Time:  O(n)
// Space: O(n)
// simulation
class Solution2 {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> q(nums);
        while (size(q) != 1) {
            vector<int> new_q;
            for (int i = 0; i < size(q) / 2; ++i) {
                new_q.emplace_back(i % 2 == 0 ? min(q[2 * i], q[2 * i + 1]) : max(q[2 * i], q[2 * i + 1]));
            }
            q = move(new_q);
        }
        return q[0];
    }
};
