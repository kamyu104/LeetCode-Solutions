// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int count = 0;
        bool visited[9] = {false};
        // 1, 3, 7, 9
        numberOfPatternsHelper(m, n, 0, 0, 1, visited, &count);
        // 2, 4, 6, 8
        numberOfPatternsHelper(m, n, 0, 1, 1, visited, &count);
        count *= 4;
        // 5
        numberOfPatternsHelper(m, n, 1, 1, 1, visited, &count);
        return count;
    }

private:
    const vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
        {2, 1}, {2, -1}, {-2, -1}, {-2, 1},
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
    };

    void numberOfPatternsHelper(int m, int n, int i, int j, int level,
                                bool visited[], int *count) {
        if (level > n) {
            return;
        }

        if (level >= m) {
            ++(*count);
        }

        visited[convert(i, j)] = true;

        for (const auto& direction : directions) {
            auto x = i + direction[0];
            auto y = j + direction[1];
            if (valid(x, y)) {
                if (!visited[convert(x, y)]) {
                    numberOfPatternsHelper(m, n, x, y, level + 1, visited, count);
                } else {
                    x += direction[0];
                    y += direction[1];
                    if (valid(x, y) && !visited[convert(x, y)]) {
                        numberOfPatternsHelper(m, n, x, y, level + 1, visited, count);
                    }
                }
            }
        }

        visited[convert(i, j)] = false;
    }

    int convert(int i, int j) {
        return 3 * i + j;
    }

    bool valid(int i, int j) {
        return i >= 0 && i < 3 && j >= 0 && j < 3;
    }
};
