// Time:  O((m * n) * (m * n)!)
// Space: O((m * n) * (m * n)!)

// A* Search Algorithm
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const auto& R = board.size(), C = board[0].size();
        vector<int> begin, end;
        unordered_map<int, pair<int, int>> expected;
        int zero_idx = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                auto val = (C * i + j + 1) % (R * C);
                expected[val] = {i, j};
                if (board[i][j] == 0) {
                    zero_idx = begin.size();
                }
                begin.emplace_back(board[i][j]);
                end.emplace_back(val);
            }
        }
        
        int min_steps = heuristic_estimate(begin, R, C, expected);
        unordered_set<vector<int>, Hash<vector<int>>> lookup;
        vector<pair<int, vector<int>>> closer{make_pair(zero_idx, begin)}, detour;
        while (true) {
            if (closer.empty()) {
                if (detour.empty()) {
                    return -1;
                }
                min_steps += 2;
                swap(closer, detour);
            }
            int zero;
            vector<int> board;
            tie(zero, board) = closer.back(); closer.pop_back();
            if (board == end) {
                return min_steps;
            }
            if (!lookup.count(board)) {
                lookup.emplace(board);
                int r = zero / C;
                int c = zero % C;
                static const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (const auto& direction : directions) {
                    int i = r + direction.first;
                    int j = c + direction.second;
                    if (0 <= i && i < R && 0 <= j && j < C) {
                        auto new_zero = C * i + j;
                        auto new_board = board;
                        swap(new_board[zero], new_board[new_zero]);
                        int r2, c2;
                        tie(r2, c2) = expected[board[new_zero]];
                        int r1 = zero / C;
                        int c1 = zero % C;
                        int r0 = new_zero / C;
                        int c0 = new_zero % C;
                        bool is_closer = dot({r1 - r0, c1 - c0}, {r2 - r0, c2 - c0}) > 0;
                        is_closer ? closer.emplace_back(new_zero, new_board) : detour.emplace_back(new_zero, new_board);
                    }
                }
            }
        }

        return min_steps;
    }

private:
    int heuristic_estimate(const vector<int>& board, int R, int C, const unordered_map<int, pair<int, int>>& expected) {
        int result = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                const auto& val = board[C * i + j];
                if (val == 0) {
                    continue;
                }
                int r, c;
                tie(r, c) = expected.at(val);
                result += abs(r - i) + abs(c - j);
            }
        }
        return result;
    }

    inline int dot(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
                        
    template<typename ContType>
    struct Hash {
        size_t operator()(const ContType& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<typename ContType::value_type>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
};

// Time:  O((m * n) * (m * n)! * log((m * n)!))
// Space: O((m * n) * (m * n)!)
// A* Search Algorithm
class Solution2 {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const auto& R = board.size(), C = board[0].size();
        vector<int> begin, end;
        unordered_map<int, pair<int, int>> expected;
        int zero_idx = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                auto val = (C * i + j + 1) % (R * C);
                expected[val] = {i, j};
                if (board[i][j] == 0) {
                    zero_idx = begin.size();
                }
                begin.emplace_back(board[i][j]);
                end.emplace_back(val);
            }
        }
        vector<int> end_wrong(end);
        swap(end_wrong[end_wrong.size() - 2], end_wrong[end_wrong.size() - 3]);
           
        using P = tuple<int, int, int, vector<int>>;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        min_heap.emplace(make_tuple(0, 0, zero_idx, begin));
        unordered_map<vector<int>, int, Hash<vector<int>>> lookup;
        lookup[begin] = 0;
        while (!min_heap.empty()) {
            int f, g, zero;
            vector<int> board;
            tie(f, g, zero, board) = min_heap.top(); min_heap.pop();
            if (board == end) {
                return g;
            }
            if (board == end_wrong) {
                return -1;
            }
            if (f > lookup[board]) {
                continue;
            }
            int r = zero / C;
            int c = zero % C;
            static const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (const auto& direction : directions) {
                int i = r + direction.first;
                int j = c + direction.second;
                if (0 <= i && i < R && 0 <= j && j < C) {
                    auto new_zero = C * i + j;
                    auto new_board = board;
                    swap(new_board[zero], new_board[new_zero]);
                    f = g + 1 + heuristic_estimate(new_board, R, C, expected);
                    if (!lookup.count(new_board) || f < lookup[new_board])
                        lookup[new_board] = f;
                        min_heap.emplace(make_tuple(f, g + 1, new_zero, new_board));
                    }
                }
            }
        }
        return -1;
    }

private:
    int heuristic_estimate(const vector<int>& board, int R, int C, const unordered_map<int, pair<int, int>>& expected) {
        int result = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                const auto& val = board[C * i + j];
                if (val == 0) {
                    continue;
                }
                int r, c;
                tie(r, c) = expected.at(val);
                result += abs(r - i) + abs(c - j);
            }
        }
        return result;
    }
                        
    template<typename ContType>
    struct Hash {
        size_t operator()(const ContType& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<typename ContType::value_type>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
};
