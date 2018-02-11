// Time:  O(n^2)
// Space: O(n)

class Solution {
public:    
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        unordered_map<vector<int>, int, Hash<vector<int>>> row_lookup, col_lookup;
        for (int i = 0; i < N; ++i) {
            const auto& row = board[i];
            ++row_lookup[row];
            if (row_lookup.size() > 2) {
                return -1;
            }
        }
        for (int j = 0; j < N; ++j) {
            vector<int> col;
            for (int i = 0; i < N; ++i) {
                col.emplace_back(board[i][j]);
            }
            ++col_lookup[col];
            if (col_lookup.size() > 2) {
                return -1;
            }
        }
        
        int row_count = move(N, row_lookup);
        if (row_count < 0) {
            return -1;
        }
        int col_count = move(N, col_lookup);
        if (col_count < 0) {
            return -1;
        }
        return row_count + col_count;
    }

private:
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
    
    int move(int N, const unordered_map<vector<int>, int, Hash<vector<int>>>& lookup) {
        if (lookup.size() != 2 ||
            min(lookup.begin()->second, next(lookup.begin())->second) != N / 2 ||
            max(lookup.begin()->second, next(lookup.begin())->second) != (N + 1) / 2) {
            return -1;
        }
        const auto& seq1 = lookup.begin()->first;
        const auto& seq2 = next(lookup.begin())->first;
        for (int i = 0; i < N; ++i) {
            if (seq1[i] == seq2[i]) {
                return -1;
            }
        }

        vector<int> begins = (N % 2) ? vector<int>{static_cast<int>(std::count(seq1.begin(), seq1.end(), 1) * 2 > N)} :
                                       vector<int>{0, 1};
        int result = numeric_limits<int>::max();
        for (const auto& begin : begins) {
            int i = begin;
            int sum = 0;
            for (const auto& v : seq1) {
                sum += (i - v + 2) % 2;
                ++i;
            }
            result = min(result, sum / 2);
        }
        return result;
    }
};
