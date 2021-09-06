// Time:  O((b+h)^2 * h!*(b+h-1)!/(b-1)!)
// Space: O((b+h) * h!*(b+h-1)!/(b-1)!)

// brute force solution with worse complexity but pass
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string, int>> lookup;
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
            for (int j = 0; j <= board.size(); ++j) {
                const auto& next_board = shrink(board.substr(0, j) + hand.substr(i, 1) + board.substr(j));
                const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
            }
        }
        return (*lookup)[board][hand] = result;
    }
    
    string shrink(string s) {  // Time: O(n^2), Space: O(1)
        bool changed = true;
        while (changed) {
            changed = false;
            for (int start = 0, i = 0; start < size(s); ++start) {
                while(i < size(s) && s[start] == s[i]) {
                    ++i;
                }
                if (i - start >= 3) {
                    s = s.substr(0, start) + s.substr(i); 
                    changed = true;
                    break;
                } 
            }
        }
        return s;
    }

    static const int MAX_STEP = 6;
};

// Time:  O((b+h) * h!*(b+h-1)!/(b-1)!)
// Space: O((b+h) * h!*(b+h-1)!/(b-1)!)
// brute force solution
class Solution_TLE {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string, int>> lookup;
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
            for (int j = 0; j <= board.size(); ++j) {
                const auto& next_board = shrink(board.substr(0, j) + hand.substr(i, 1) + board.substr(j));
                const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
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
                } else if (!s.empty() && i - start < 3) {
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

// Time:  O((b * h) * b * b! * h!)
// Space: O(b * b! * h!)
// greedy solution without proof (possibly incorrect) 
class Solution_GREEDY_ACCEPT_BUT_NOT_PROVED {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string, int>> lookup;
        sort(hand.begin(), hand.end()); 
        int result = findMinStepHelper(board, hand, &lookup);
        if (result == MAX_STEP) {
            unordered_map<string, unordered_map<string, int>> lookup2;
            result = findMinStepHelper2(board, hand, &lookup2);
        }
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
            while (j < board.size()) {
                int k = board.find(hand[i], j);
                if (k == string::npos) {
                    break;
                }
                if (k < board.size() - 1 && board[k] == board[k + 1]) {
                    const auto& next_board = shrink(board.substr(0, k) + board.substr(k + 2));
                    const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
                    ++k;
                } else if (i > 0 && hand[i] == hand[i - 1]) {
                    const auto& next_board = shrink(board.substr(0, k) + board.substr(k + 1));
                    const auto& next_hand = hand.substr(0, i - 1) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 2);
                }
                j = k + 1;
            }
        }
        return (*lookup)[board][hand] = result;
    }

    int findMinStepHelper2(const string& board, const string& hand,
                          unordered_map<string, unordered_map<string, int>> *lookup) {
        int result = MAX_STEP;
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j <= board.size(); ++j) {
                const auto& next_board = shrink(board.substr(0, j) + hand.substr(i, 1) + board.substr(j));
                const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
            }
        }
        return result;
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
                } else if (!s.empty() && i - start < 3) {
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

// Time:  O(b * b! * h!)
// Space: O(b * b! * h!)
// if a ball can be only inserted beside a ball with same color,
// we can do by this solution
class Solution_WRONG_GREEDY_AND_NOT_ACCEPT_NOW {
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
            while (j < board.size()) {
                int k = board.find(hand[i], j);
                if (k == string::npos) {
                    break;
                }
                if (k < board.size() - 1 && board[k] == board[k + 1]) {
                    const auto& next_board = shrink(board.substr(0, k) + board.substr(k + 2));
                    const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
                    ++k;
                } else if (i > 0 && hand[i] == hand[i - 1]) {
                    const auto& next_board = shrink(board.substr(0, k) + board.substr(k + 1));
                    const auto& next_hand = hand.substr(0, i - 1) + hand.substr(i + 1);
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
                } else if (!s.empty() && i - start < 3) {
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
