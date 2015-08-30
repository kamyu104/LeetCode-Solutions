// Time:  O(n)
// Space: O(1)

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for (size_t i = 0; i < strs.size(); ++i) {
            size_t len = strs[i].length();
            string tmp;
            for (size_t i = 0, mask = 0xff; i < sizeof(size_t); ++i, mask <<= 8) {
                tmp.push_back(len & mask);
            }
            reverse(tmp.begin(), tmp.end());
            s.append(tmp);
            s.append(strs[i]);
        }
    
        return s;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t pos = 0;
    
        while (pos + sizeof(size_t) <= s.length()) {
            size_t len = 0;
            for (size_t i = 0; i < sizeof(size_t); ++i) {
                len <<= 8;
                len += static_cast<unsigned char>(s[pos++]);
            } 
    
            strs.push_back(s.substr(pos, len));
            pos += len;
        }
    
        return strs;
    }
};
