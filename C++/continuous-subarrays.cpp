// Time:  O(n)
// Space: O(n)

// mono deque, two pointers
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> mn, mx; 
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            while (!empty(mn) && nums[mn.back()] > nums[right]) {
                mn.pop_back();
            }
            mn.emplace_back(right);
            while (!empty(mx) && nums[mx.back()] < nums[right]) {
                mx.pop_back();
            }
            mx.emplace_back(right);
            while (!(nums[right] - nums[mn.front()] <= 2)) {
                left = max(left, mn.front() + 1);
                mn.pop_front();
            }
             while (!(nums[mx.front()] - nums[right] <= 2)) {
                left = max(left, mx.front() + 1);
                mx.pop_front();
            }
            result += right - left + 1;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bst, two pointers
class Solution2 {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int64_t result = 0;
        map<int, int> lookup;
        for (int right = 0, left = 0; right < nums.size(); ++right) {
            lookup[nums[right]] = right;
            for (auto it = begin(lookup); nums[right] - it->first > 2;) {
                left = max(left, it->second + 1);
                lookup.erase(it++);
            }
            for (auto it = prev(end(lookup)); it->first - nums[right] > 2;) {
                left = max(left, it->second + 1);
                lookup.erase(it--);
            }
            result += right - left + 1;
        }
        return result;
    }
};

