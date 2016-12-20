// Time:  O((m + n) * logn), m is the number of the houses, n is the number of the heaters.
// Space: O(1)

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int min_radius = 0;
        for (const auto& house : houses) {
        	auto equal_or_larger = lower_bound(heaters.cbegin(), heaters.cend(), house);
        	auto curr_radius = numeric_limits<int>::max();
        	if (equal_or_larger != heaters.cend()) {
        	    curr_radius = *equal_or_larger - house;
        	}
        	if (equal_or_larger != heaters.cbegin()) {
        	    auto smaller = prev(equal_or_larger);
        	    curr_radius = min(curr_radius, house - *smaller);
        	}
        	min_radius = max(min_radius, curr_radius);
        }
        return min_radius;
    }
};
