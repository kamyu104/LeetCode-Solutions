// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1, result = 1;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i]) {
                if (prev < 0) {
                    result = i;
                } else {
                    result = max(result, (i - prev) / 2);
                }
                prev = i;
            }
        }
        return max(result, static_cast<int>(seats.size()) - 1 - prev);
    }
};
