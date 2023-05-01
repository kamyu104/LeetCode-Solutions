// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        const auto& f = [](const auto& arr) {
            static const int k = 2;

            int result = 0;
            for (int i = 0, cnt = 0; i < size(arr); ++i) {
                result += cnt ? 2 * arr[i] : arr[i];
                cnt += static_cast<int>(arr[i] == 10);
                if (i - k >= 0) {
                    cnt -= static_cast<int>(arr[i - k] == 10);
                }
            }
            return result;
        };

        const int a = f(player1), b = f(player2);
        return a > b ? 1 : (a < b ? 2 : 0);
    }
};
