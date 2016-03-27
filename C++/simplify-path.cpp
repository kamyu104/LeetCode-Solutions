// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        vector<string> tokens(move(split(path, '/')));
        for (const auto& token : tokens) {
            if (token == ".." && !names.empty()) {
                names.pop_back();
            } else if (token != ".." && token != "." && !token.empty()) {
                names.emplace_back(token);
            }
        }
        return string("/").append(join(names, '/'));
    }

private:
    // Split string by delimitor.
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }

    // Join strings with delimitor.
    string join(const vector<string>& names, const char delim) {
        ostringstream ss;
        if (!names.empty()) {
            const string delim_str(1, delim);
            copy(names.cbegin(), prev(names.cend()),
                 ostream_iterator<string>(ss, delim_str.c_str()));
            ss << names.back();
        }
        return ss.str();
    }
};
