// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        using namespace std::placeholders;  // for _1, _2, _3...

        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        function<bool(const int)> findLeft = bind(searchColumns, image, true, _1);
        const int left = binarySearch(0, y - 1, findLeft);
    
        function<bool(const int)> findRight = bind(searchColumns, image, false, _1);
        const int right = binarySearch(y + 1, image[0].size() - 1, findRight);

        function<bool(const int)> findTop = bind(searchRows, image, true, _1);
        const int top = binarySearch(0, x - 1, findTop);

        function<bool(const int)> findBottom = bind(searchRows, image, false, _1);
        const int bottom = binarySearch(x + 1, image.size() - 1, findBottom);

        return (right - left) * (bottom - top);
    }
    
private:
    int binarySearch(int left, int right, function<bool(const int)>& find) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


class Solution2 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        const int left = binarySearch(0, y - 1, searchColumns, image, true);
        const int right = binarySearch(y + 1, image[0].size() - 1, searchColumns, image, false);
        const int top = binarySearch(0, x - 1, searchRows, image, true);
        const int bottom = binarySearch(x + 1, image.size() - 1, searchRows, image, false);

        return (right - left) * (bottom - top);
    }
    
private:
    int binarySearch(int left, int right,
                     const function<bool(const vector<vector<char>>&, bool, const int)>& find,
                     const vector<vector<char>>& image,
                     bool has_one) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(image, has_one, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
