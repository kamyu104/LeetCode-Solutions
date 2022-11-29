// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int bestClosingTime(string customers) {
        int result = 0, mx = 0, curr = 0;
        for (int i = 0; i < size(customers); ++i) {
            curr += customers[i] == 'Y' ? 1 : -1;
            if (curr > mx) {
                mx = curr;
                result = i + 1;
            }
        }
        return result;
    }
};
