// Time:  O(sqrt(n))
// Space: O(1)

// greedy
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) {
            return {};
        }
        vector<long long> result;
        for (int i = 2; i <= finalSum; i += 2) {
            result.emplace_back(i);
            finalSum -= i;
        }
        result.back() += finalSum;
        return result;
    }
};
