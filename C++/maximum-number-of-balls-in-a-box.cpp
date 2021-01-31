// Time:  O(nlogm)
// Space: O(logm)

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int total = 0;
            for (int d = i; d; d /= 10) {
                total += d % 10;
            }
            ++count[total];
        }
        return max_element(cbegin(count), cend(count),
                           [](const auto& a, const auto& b) {
                               return a.second < b.second;
                           })->second;
    }
};
