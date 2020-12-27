// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2);
        for (const auto& s : students) {
            ++count[s];
        }
        int i = 0;
        for (; i < size(sandwiches); ++i) {
            if (!count[sandwiches[i]]) {
                break;
            }
            --count[sandwiches[i]];
        }
        return size(sandwiches) - i;
    }
};
