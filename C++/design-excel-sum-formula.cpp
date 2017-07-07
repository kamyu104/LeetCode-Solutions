// Time:  set: O((r * c)^2)
//        get: O(1)
//        sum: O((r * c)^2)
// Space: O(r * c)

class Excel {
public:
    Excel(int H, char W) : Exl_(H + 1, vector<int>(W - 'A' + 1)) {
    }
    
    // Time:  O((r * c)^2)
    void set(int r, char c, int v) {
        auto col = c - 'A';
        reset_dependency(r, col);
        update_others(r, col, v);
    }
    
    // Time:  O(1)
    int get(int r, char c) {
        return Exl_[r][c - 'A'];
    }

    // Time:  O((r * c)^2)
    int sum(int r, char c, vector<string> strs) {
        auto col = c - 'A';
        reset_dependency(r, col);
        auto result = calc_and_update_dependency(r, col, strs);
        update_others(r, col, result);
        return result;
    }

private:
    // Time:  O(r * c)
    void reset_dependency(int r, int col) {
        auto key = r * 26 + col;
        if (bward_.count(key)) {
            for (const auto& k : bward_[key]) {
                fward_[k].erase(key);
            }
            bward_.erase(key);
        }
    }

    // Time:  O(r * c * l), l is the length of strs
    int calc_and_update_dependency(int r, int col, const vector<string>& strs) {
        auto result = 0;
        for (const auto& s : strs) {
            int p = s.find(':'), left, right, top, bottom;
            left = s[0] - 'A';
            right = s[p + 1] - 'A';
            top = (p == string::npos) ? stoi(s.substr(1)) : stoi(s.substr(1, p - 1));
            bottom = stoi(s.substr(p + 2));
            for (int i = top; i <= bottom; ++i) {
                for (int j = left; j <= right; ++j) {
                    result += Exl_[i][j];
                    ++fward_[i * 26 + j][r * 26 + col];
                    bward_[r * 26 + col].emplace(i * 26 + j);
                }
            }
        }
        return result;
    }

    // Time:  O((r * c)^2)
    void update_others(int r, int col, int v) {
        auto prev = Exl_[r][col];
        Exl_[r][col] = v;
        queue<pair<int, int>> q;
        q.emplace(make_pair(r * 26 + col, v - prev));
        while (!q.empty()) {
            int key, diff;
            tie(key, diff) = q.front(), q.pop();
            if (fward_.count(key)) {
                for (auto it = fward_[key].begin(); it != fward_[key].end(); ++it) {
                    int k, count;
                    tie(k, count) = *it;
                    q.emplace(make_pair(k, diff * count));
                    Exl_[k / 26][k % 26] += diff * count;
                }
            }
        }
    }
    
    unordered_map<int, unordered_map<int, int>> fward_;
    unordered_map<int, unordered_set<int>> bward_;
    vector<vector<int>> Exl_;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
