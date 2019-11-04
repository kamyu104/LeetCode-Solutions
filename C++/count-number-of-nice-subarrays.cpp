// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(const vector<int>& nums, int k) {
        int result = 0, left = 0, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count += nums[right] % 2;
            while (count > k) {
                count -= nums[left] % 2;
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(k)
class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        deque<int> dq = {-1};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) {
                dq.emplace_back(i);
            }
            if (dq.size() > k + 1) {
                dq.pop_front();
            }
            if (dq.size() == k + 1) {
                result += dq[1] - dq[0];
            }
        }
        return result;
    }
};
