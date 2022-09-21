// Time:  O(1)
// Space: O(1)

// prefix sum
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const vector<int> NUMS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(size(NUMS) + 1);
        for (int i = 0; i < size(NUMS); ++i) {
            prefix[i + 1] = prefix[i] + NUMS[i];
        }
        
        const auto& day = [&](const auto& date) {
            return prefix[stoi(date.substr(0, 2)) - 1] + stoi(date.substr(3));
        };
        return max(day(min(leaveAlice, leaveBob)) - day(max(arriveAlice, arriveBob)) + 1, 0);
    }
};
