// Time:  O(a^2 + n), a is the number of ages,
//                    n is the number of people
// Space: O(a)

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (const auto &age : ages) {
            ++count[age];
        }
        int result = 0;
        for (const auto &a: count) {
            for (const auto &b: count) {
                if (request(a.first, b.first)) {
                    result += a.second * (b.second - (a.first == b.first ? 1 : 0));
                }
            }
        }
        return result;
    }

private:
    bool request(int a, int b) {
        return 0.5 * a + 7 < b && b <= a;
    }
};
