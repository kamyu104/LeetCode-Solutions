// Time:  O(nlogn)
// Space: O(n)

// heap
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int64_t result = 0;
        priority_queue<int> max_heap;
        for (int i = 0; i < size(nums); ++i) {
            max_heap.emplace(nums[i]);
            if (s[i] == '1') {
                result += max_heap.top();
                max_heap.pop();
            }
        }
        return result;
    }
};
