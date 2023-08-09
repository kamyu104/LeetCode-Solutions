// Time:  O(n)
// Space: O(n)

// deque
class Solution {
public:
    string finalString(string s) {
        deque<char> dq;
        int parity = 0;
        for (const auto& x : s) {
            if (x == 'i') {
                parity ^= 1;
            } else {
                if (parity) {
                    dq.emplace_front(x);
                } else {
                    dq.emplace_back(x);
                }
            }
        }
        if (parity) {
            reverse(begin(dq), end(dq));
        }
        return string(cbegin(dq), cend(dq));
    }
};
