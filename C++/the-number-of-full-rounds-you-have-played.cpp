// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3));
        int finish = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3));
        if (start > finish) {
            finish += 1440;
        }
        return max(finish / 15 - (start + 15 - 1) / 15, 0);
    }
};


// Time:  O(1)
// Space: O(1)
class Solution2 {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int h1 = stoi(startTime.substr(0, 2));
        int m1 = stoi(startTime.substr(3));
        int h2 = stoi(finishTime.substr(0, 2));
        int m2 = stoi(finishTime.substr(3));
        if (m1 > m2) {
            --h2;
            m2 += 60;
        }
        return max((h2 - h1 + 24) % 24 * 4 + m2 / 15 - (m1 + 15 - 1) / 15, 0);
    }
};
