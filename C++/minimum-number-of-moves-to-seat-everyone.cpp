// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int result = 0;
        for (int i = 0; i < size(seats); ++i) {
            result += abs(seats[i] - students[i]);
        }
        return result;
    }
};
