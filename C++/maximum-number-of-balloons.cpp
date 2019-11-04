// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        static const string TARGET = "balloon";
        unordered_map<int, int> source_count, target_count;
        for (const auto& c : text) {
            ++source_count[c];
        }
        for (const auto& c : TARGET) {
            ++target_count[c];
        }
        int result = numeric_limits<int>::max();
        for (const auto& [c, count] : target_count) {
            result = min(result, source_count[c] / count);
        }
        return result;
    }
};
