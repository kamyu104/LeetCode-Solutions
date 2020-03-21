// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_map<int, bool>> lookup;
        for (const auto& seat : reservedSeats) {
            if (2 <= seat[1] && seat[1] <= 5) {
                lookup[seat[0]][0] = true;
            }
            if (4 <= seat[1] && seat[1] <= 7) {
                lookup[seat[0]][1] = true;
            }
            if (6 <= seat[1] && seat[1] <= 9) {
                lookup[seat[0]][2] = true;
            }
        }
        int result = 2 * n;
        for (auto& [_, reserved] : lookup) {
            if (!reserved[0] && !reserved[2]) {
                continue;
            }
            if (!reserved[0] || !reserved[1] || !reserved[2]) {
                --result;
                continue;
            }
            result -= 2;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(begin(reservedSeats), end(reservedSeats));
        int result = 2 * n;
        for (int i = 0; i < reservedSeats.size();) {
            unordered_map<int, bool> reserved;
            int curr = reservedSeats[i][0];
            while (i < reservedSeats.size() && reservedSeats[i][0] == curr) {
                if (2 <= reservedSeats[i][1] && reservedSeats[i][1] <= 5) {
                    reserved[0] = true;
                }
                if (4 <= reservedSeats[i][1] && reservedSeats[i][1] <= 7) {
                    reserved[1] = true;
                }
                if (6 <= reservedSeats[i][1] && reservedSeats[i][1] <= 9) {
                    reserved[2] = true;
                }
                ++i;
            }
            if (!reserved[0] && !reserved[2]) {
                continue;
            }
            if (!reserved[0] || !reserved[1] || !reserved[2]) {
                --result;
                continue;
            }
            result -= 2;
        }
        return result;
    }
};
