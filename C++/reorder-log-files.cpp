// Time:  O(nlogn * l), n is the length of files, l is the average length of strings
// Space: O(l)

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto pivot = stable_partition(logs.begin(), logs.end(),
                                      [](const auto& log) {
                                          return isalpha(log.back());
                                      });
        sort(logs.begin(), pivot,
             [](const auto& a, const auto& b) {
                 int i = a.find_first_of(' '), j = b.find_first_of(' ');
                 return a.substr(i, a.length() - i) < b.substr(j, b.length() - j);
             });
        return logs;
    }
};
