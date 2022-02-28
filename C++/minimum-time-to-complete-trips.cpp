// Time:  O(nlogr)
// Space: O(1)

// binary search
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        const auto& check = [](const auto& time, const auto& totalTrips, const auto& x) {
            return accumulate(cbegin(time), cend(time), 0ll,
                              [&x](const auto& total, const auto& t) {
                                 return total + x / t; 
                              }) >= totalTrips;
        };
        int64_t left = 1, right = static_cast<int64_t>(*max_element(cbegin(time), cend(time))) * totalTrips;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(time, totalTrips, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
