// Time:  O(1)
// Space: O(1)

// string
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        const auto& to_seconds = [](const auto& x) {
            const auto& h = stoi(x.substr(0, 2));
            const auto& m = stoi(x.substr(3, 2));
            const auto& s = stoi(x.substr(6, 2));
            return h * 60 * 60 + m * 60 + s;
        };

        return to_seconds(endTime) - to_seconds(startTime);
    }
};
