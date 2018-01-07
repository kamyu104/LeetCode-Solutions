// Time:  O(logn) = O(1), n is the value of the integer, which is less than 2^31 - 1
// Space: O(1)

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        const unordered_map<int, string> lookup = {{0, "Zero"}, {1, "One"}, {2, "Two"},
                                                   {3, "Three"}, {4, "Four"}, {5, "Five"},
                                                   {6, "Six"}, {7, "Seven"}, {8, "Eight"},
                                                   {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
                                                   {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
                                                   {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
                                                   {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"},
                                                   {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
                                                   {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"},
                                                   {90, "Ninety"}};
        const vector<string> unit{"", "Thousand", "Million", "Billion"};

        vector<string> res;
        int i = 0;
        while (num) {
            const int cur = num % 1000;
            if (num % 1000) {
                res.emplace_back(threeDigits(cur, lookup, unit[i]));
            }
            num /= 1000;
            ++i;
        }
        reverse(res.begin(), res.end());
        return join(res, " ");
    }
    
    string join(const vector<string>& strings, const string& delim) {
        if (strings.empty()) {
            return "";
        }
        ostringstream imploded;
        copy(strings.begin(), prev(strings.end()), ostream_iterator<string>(imploded, delim.c_str()));
        return imploded.str() + *prev(strings.end());
    }

    string threeDigits(const int& num, const unordered_map<int, string>& lookup, const string& unit) {
        vector<string> res;
        if (num / 100) {
            res.emplace_back(lookup.find(num / 100)->second + " " + "Hundred");
        }
        if (num % 100) {
            res.emplace_back(twoDigits(num % 100, lookup));
        }
        if (!unit.empty()) {
            res.emplace_back(unit);
        }
        return join(res, " ");
    }
    
    string twoDigits(const int& num, const unordered_map<int, string>& lookup) {
        if (lookup.find(num) != lookup.end()) {
            return lookup.find(num)->second;
        }
        return lookup.find((num / 10) * 10)->second + " " + lookup.find(num % 10)->second; 
    }
};
