// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        static const int N = 60 * 24;
        vector<int> minutes;
        for (const auto& t : timePoints) {
            minutes.emplace_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3)));
        }
        sort(minutes.begin(), minutes.end());
        int result = numeric_limits<int>::max();
        for (int i = 0; i < timePoints.size(); ++i) {
            result = min(result, (N + minutes[(i + 1) % timePoints.size()] - minutes[i]) % N);
        }
        return result;
    }
};
