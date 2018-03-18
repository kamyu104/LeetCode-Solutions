// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string similarRGB(string color) {
        string result = "#";
        result += round(color.substr(1, 2));
        result += round(color.substr(3, 2));
        result += round(color.substr(5, 2));
        return result;
    }

private:
    string round(const string& color) {
        std::stringstream in(color);
        int decimal = 0;
        in >> std::hex >> decimal;
        decimal = decimal / 17 + (decimal % 17 > 8 ? 1 : 0);
        std::stringstream out;
        out << std::setfill('0') << std::setw(2) << std::hex <<  17 * q;
        return out.str();
    }
};
