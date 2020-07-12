// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reformatDate(string date) {
        static const unordered_map<string, int> lookup = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
            {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };
        stringstream ss;
        int y = stoi(date.substr(date.length() - 4));
        ss << setfill('0') << setw(4) << y;
        int m = lookup.at(date.substr(date.length() - 4 - 4, 3));
        ss << "-" << setfill('0') << setw(2) << m;
        int d = stoi(date.substr(0, date.find(' ', 0) - 2));
        ss << "-" << setfill('0') << setw(2) << d;
        return ss.str();
    }
};

