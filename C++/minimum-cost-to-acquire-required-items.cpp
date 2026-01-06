// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        const int64_t mn = min(need1, need2);
        const int64_t mx = max(need1, need2);
        return mn * min(cost1 + cost2, costBoth) + min((need1 - mn) * cost1 + (need2 - mn) * cost2, (mx - mn) * costBoth);
    }
};

// Time:  O(1)
// Space: O(1)
// math
class Solution2 {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        const int64_t mn = min(need1, need2);
        const int64_t mx = max(need1, need2);
        return min({static_cast<int64_t>(need1) * cost1 + static_cast<int64_t>(need2) * cost2,
                    mn * costBoth + (need1 - mn) * cost1 + (need2 - mn) * cost2,
                    mx * costBoth});
    }
};
