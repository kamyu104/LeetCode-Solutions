// Time:  O(b * b! * h!)
// Space: O(b * b! * h!)

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string, int>> lookup;
        sort(hand.begin(), hand.end()); 
        int result = findMinStepHelper(board, hand, &lookup);
        return result > hand.size() ? -1 : result;
    }

private:
    int findMinStepHelper(const string& board, const string& hand,
                          unordered_map<string, unordered_map<string, int>> *lookup) {
        if (board.empty()) {
            return 0;
        }
        if (hand.empty()) {
            return MAX_STEP;
        }
        if ((*lookup)[board][hand]) {
            return (*lookup)[board][hand];
        }

        int result = MAX_STEP;
        for (int i = 0; i < hand.size(); ++i) {
            int j = 0;
            int n = board.size();
            while (j < n) {
                int k = board.find(hand[i], j);
                if (k == string::npos) {
                    break;
                }
                if (k < n - 1 && board[k] == board[k + 1]) {
                    string next_board = shrink(board.substr(0, k) + board.substr(k + 2));
                    string next_hand = hand.substr(0, i) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
                    ++k;
                } else if (i > 0 && hand[i] == hand[i - 1]) {
                    string next_board = shrink(board.substr(0, k) + board.substr(k + 1));
                    string next_hand = hand.substr(0, i - 1) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 2);
                }
                j = k + 1;
            }
        }

        return (*lookup)[board][hand] = result;
    }
    
    string shrink(const string& s) {  // Time: O(n), Space: O(n)
        vector<pair<char, int>> stack;
        for (int i = 0, start = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[start]) {
                if (!stack.empty() && stack.back().first == s[start]) {
                    stack.back().second += i - start;
                    if (stack.back().second >= 3) {
                        stack.pop_back();
                    }
                } else if (i - start < 3) {
                     stack.emplace_back(s[start], i - start);
                }
                start = i;
            }
        }
        string result;
        for (const auto& p : stack) {
            result += string(p.second, p.first);
        }
        return result;
    }

    static const int MAX_STEP = 6;
};
