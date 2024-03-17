// Time:  O(q + nlogn)
// Space: O(n)

// hash table, heap
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long total = accumulate(cbegin(nums), cend(nums), 0ll);
        vector<bool> lookup(size(nums));
        vector<pair<int, int>> arr(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            arr[i] = {nums[i], i};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap(cbegin(arr), cend(arr));
        vector<long long> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const int idx = queries[i][0];
            const int k = queries[i][1];
            if (!lookup[idx]) {
                lookup[idx] = true;
                total -= nums[idx];
            }
            for (int _ = 0; _ < k; ++_) {
                while (!empty(min_heap)) {
                    const auto [x, i] = min_heap.top(); min_heap.pop();
                    if (lookup[i]) {
                        continue;
                    }
                    lookup[i] = true;
                    total -= x;
                    break;
                }
                if (empty(min_heap)) {
                    break;
                }
            }
            result[i] = total;
        }
        return result;
    }
};
