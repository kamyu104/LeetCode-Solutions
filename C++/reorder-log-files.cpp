// Time:  O(nlogn * m)n is the length of vector, m is the average length of strings
// Space: O(1)

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

    sort(logs.begin()
         ,stable_partition(begin(logs)
                           , end(logs)
                           , [] (auto s) { return isalpha(s.back()); })
         , [] (auto i, auto j) {return i.substr(i.find_first_of(' ')) < j.substr(j.find_first_of(' '));});                    
    return logs;
    }
};