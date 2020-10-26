// Time:  O(n)
// Space: O(n)

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = find_guess_with_most_frequent_chars(wordlist, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (match(wordlist[guess], wordlist[j]) == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int find_guess_with_most_frequent_chars(
        const vector<string>& wordlist,
        const vector<int>& possible) {
        vector<vector<int>> count(6, vector<int>(26));
        for (int i = 0; i < 6; ++i) {
            for (const auto& p : possible) {
                ++count[i][wordlist[p][i] - 'a'];
            }
        }
        int guess = 0, max_score = 0;
        for (const auto& p : possible) {
            int score = 0;
            for (int i = 0; i < 6; ++i) {
                score += count[i][wordlist[p][i] - 'a'];
            }
            if (score > max_score) {
                max_score = score;
                guess = p;
            }
        }
        return guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<vector<int>> H(size(wordlist), vector<int>(size(wordlist)));
        for (int i = 0; i < size(wordlist); ++i) {
            for (int j = 0; j < size(wordlist); ++j) {
                H[i][j] = match(wordlist[i], wordlist[j]);
            }
        }

        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = solve(H, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (H[guess][j] == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int solve(const vector<vector<int>>& H,
              const vector<int>& possible) {

        int min_max_size = size(possible);
        int best_guess = -1; 
        for (const auto& guess : possible) {
            vector<vector<int>> groups(7);
            for (const auto& j : possible) {
                if (j != guess) {
                    groups[H[guess][j]].emplace_back(j);
                }
            }
            int max_group_i = 0;
            for (int i = 0; i < size(groups); ++i) {
                if (size(groups[i]) > size(groups[max_group_i])) {
                    max_group_i = i;
                }
            }
            if (size(groups[max_group_i]) < min_max_size) {
                min_max_size = size(groups[max_group_i]);
                best_guess = guess;
            }
        }
        return best_guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution3 {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<vector<int>> H(size(wordlist), vector<int>(size(wordlist)));
        for (int i = 0; i < size(wordlist); ++i) {
            for (int j = 0; j < size(wordlist); ++j) {
                H[i][j] = match(wordlist[i], wordlist[j]);
            }
        }

        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = solve(H, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (H[guess][j] == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int solve(const vector<vector<int>>& H,
              const vector<int>& possible) {

        int min_max_size = size(possible);
        int best_guess = -1; 
        for (const auto& guess : possible) {
            vector<vector<int>> groups(7);
            for (const auto& j : possible) {
                if (j != guess) {
                    groups[H[guess][j]].emplace_back(j);
                }
            }
            int max_group_i = 0;  // assumed the size of the other groups equals to the size of 0-group
            if (size(groups[max_group_i]) < min_max_size) {
                min_max_size = size(groups[max_group_i]);
                best_guess = guess;
            }
        }
        return best_guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};
