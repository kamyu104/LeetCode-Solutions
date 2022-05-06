// Time:  O(nlogn)
// Space: O(n)

// greedy, heap
class Solution {
public:
    int convertArray(vector<int>& nums) {
        const auto& f = [](const auto& begin, const auto& end) {
            int result = 0;
            priority_queue<int> max_heap;
            for (auto it = begin; it != end; ++it) {
                if (!empty(max_heap) && *it < max_heap.top()) {
                    result += max_heap.top() - *it; max_heap.pop();
                    max_heap.emplace(*it);
                }
                max_heap.emplace(*it);
            }
            return result;
        };
        
        return min(f(cbegin(nums), cend(nums)), f(crbegin(nums), crend(nums)));
    }    
};

// Time:  O(n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    int convertArray(vector<int>& nums) {
        unordered_set<int> nums_set(cbegin(nums), cend(nums));
        vector<int> vals(cbegin(nums_set), cend(nums_set));
        sort(begin(vals), end(vals));
        const auto& f = [&](const auto& begin, const auto& end) {
            int result = 0;
            unordered_map<int, int> dp;  // dp[i]: min(cnt(j) for j in vals if j <= i)
            for (auto it = begin; it != end; ++it) {
                int prev = -1;
                for (const auto& i : vals) {
                    dp[i] = (prev != -1) ? min(dp[i] + abs(i - *it), dp[prev]) : dp[i] + abs(i - *it);
                    prev = i;
                }
            }
            return dp[vals.back()];
        };
        
        return min(f(cbegin(nums), cend(nums)), f(crbegin(nums), crend(nums)));
    }    
};
