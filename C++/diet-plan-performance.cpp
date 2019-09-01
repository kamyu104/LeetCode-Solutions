// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int total = accumulate(calories.cbegin(), calories.cbegin() + k, 0);
        int result = int(total > upper) - int(total < lower);
        for (int i = k; i < calories.size(); ++i) {
            total += calories[i] - calories[i - k];
            result += int(total > upper) - int(total < lower);
        }
        return result;
    }
};
