// Time:  O(r), r = len(result)
// Space: O(r)

// simulation, deque
class Solution {
public:
    string processStr(string s) {
        deque<char> dq;
        bool right = true;
        for (const auto& x : s) {
            if (x == '*') {
                if (empty(dq)) {
                    continue;
                }
                if (right) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            } else if (x == '#') {
                const int l = size(dq);
                for (int i = 0; i < l; ++i) {
                    dq.emplace_back(dq[i]);
                }
            } else if (x == '%') {
                right = !right;
            } else {
                if (right) {
                    dq.emplace_back(x);
                } else {
                    dq.emplace_front(x);
                }
            }
        }
        if (!right) {
            reverse(begin(dq), end(dq));
        }
        return string(cbegin(dq), cend(dq));
    }
};
