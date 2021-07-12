// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool sumGame(string num) {
        // (1) if both halfs have '?',
        //     alice will try to choose a number to maximize or minimize the diff of both half sums,
        //     and bob will try to choose the same number to minimize or maximize the diff of both half sums.
        //     in the end, it turns that only one half has '?' and the diff of both half sums is still the same as original
        // (2) if smaller half has no '?', alice wins
        // (3) if smaller half has '?'
        //     (3.1) cnt of '?' is odd, alice can choose the last number to make the diff of both half sums != 0, alice wins
        //     (3.2) cnt of '?' is even, bob can always make a pair of sum 9 no matter what alice chooses, so if larger-smaller = cnt/2 * 9, then bob wins
        int cnt = 0, total = 0;
        for (int i = 0; i < size(num); ++i) {
            if (num[i] == '?') {
                cnt += (i < size(num) / 2) ? -1 : 1;
            } else {
                total += (i < size(num) / 2) ? num[i] - '0' : -(num[i] - '0');
            }
        }
        return cnt % 2 ? true : total != cnt / 2 * 9;
    }
};
