// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        static const int THRESHOLD = 3;
        unordered_map<string, vector<int>> name_to_times;
        for (int i = 0; i < size(keyName); ++i) {
            int hour = stoi(keyTime[i].substr(0, 2));
            int minute = stoi(keyTime[i].substr(3));
            name_to_times[keyName[i]].emplace_back(hour * 60 + minute);
        }
        vector<string> result;
        for (auto& [name, times] : name_to_times) {
            sort(begin(times), end(times));
            for (int left = 0, right = 0; right < size(times); ++right) {
                while (times[right] - times[left] > 60) {
                    ++left;
                }
                if (right - left + 1 >= THRESHOLD) {
                    result.emplace_back(name);
                    break;
                }
            }
        }
        sort(begin(result), end(result));
        return result;
    }
};
