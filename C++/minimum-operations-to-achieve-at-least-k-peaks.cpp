// Time:  O(n + klogn)
// Space: O(n)

// greedy, heap
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (2 * k > size(nums)) {
            return -1;
        }
        if (!k) {
            return 0;
        }
        vector<bool> lookup(size(nums));
        vector<int> left(size(nums)), right(size(nums)), cost(size(nums));
        vector<pair<int, int>> pairs(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            left[i] = (size(nums) + (i - 1)) % size(nums);
            right[i] = (size(nums) + (i + 1)) % size(nums);
            cost[i] = max((max(nums[left[i]], nums[right[i]]) + 1) - nums[i], 0);
            pairs[i] = pair(cost[i], i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap(cbegin(pairs), cend(pairs));
        int result = 0;
        while (!empty(min_heap)) {
            const auto [c, i] = min_heap.top(); min_heap.pop();
            if (lookup[i]) {
                continue;
            }
            result += c;
            if (!--k) {
                break;
            }
            cost[i] = cost[left[i]] + cost[right[i]] - cost[i];
            min_heap.emplace(cost[i], i);
            lookup[left[i]] = lookup[right[i]] = true;
            left[i] = left[left[i]];
            right[i] = right[right[i]];
            right[left[i]] = left[right[i]] = i;
        }
        return result;
    }
};
