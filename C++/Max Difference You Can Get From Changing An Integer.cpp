class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        int n = str1.size();
        // Get max number
        int i;
        for(i = 0; i < n; i++) {
            if(str1[i] != '9') break;
        }
        char ele1 = str1[i];
        for(int k = 0; k < n; k++) {
            if(str1[k] == ele1) str1[k] = '9';
        }
        // Get min number
        char ele2 = str2[0];
        char replace = '1';
        if(ele2 == '1') {
            for(int k = 1; k < n; k++) {
                if(str2[k] != '0' && str2[k] != '1') {
                    ele2 = str2[k];
                    replace = '0';
                    break;
                }
            }
        }
        for(int k = 0; k < n; k++) {
            if(str2[k] == ele2) str2[k] = replace;
        }

        return stoi(str1) - stoi(str2);
    }
};
