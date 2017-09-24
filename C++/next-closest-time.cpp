// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string nextClosestTime(string time) {
        static const vector<int> mins = { 600, 60, 10, 1 };
        auto npos = time.find(':');
        auto curr = stoi(time.substr(0, npos)) * 60 +
                    stoi(time.substr(npos + 1));
        string result = "0000";
        for (int i = 1, d = 0; i <= 1440 && d < 4; ++i) {
            int m = (curr + i) % 1440;
            for (d = 0; d < 4; ++d) {
                result[d] = '0' + m / mins[d]; m %= mins[d];
                if (time.find(result[d]) == string::npos) {
                    break;
                }
            }
        }
        return result.substr(0, 2) + ':' + result.substr(2, 2);
    }
};
