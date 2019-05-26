// Time:  O(klogk), k is the number of distinct barcode
// Space: O(k)

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnts;
        for (const auto& barcode : barcodes) {
            ++cnts[barcode];
        }
        vector<pair<int, int>> sorted_cnts;
        for (const auto& kvp : cnts) {
            sorted_cnts.emplace_back(kvp.second, kvp.first);
        }
        sort(sorted_cnts.begin(), sorted_cnts.end(),
             greater<pair<int, int>>());
        
        int i = 0;
        for (const auto& kvp : sorted_cnts) {
            for (int j = 0; j < kvp.first; ++j) {
                barcodes[i] = kvp.second;
                i += 2;
                if (i >= barcodes.size()) {
                    i = 1;
                }
            }
        }
        return barcodes;
    }
};
