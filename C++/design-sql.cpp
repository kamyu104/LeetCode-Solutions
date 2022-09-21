// Time:  ctor:       O(t * max_m), t is the number of tables, max_m is the max number of columns in all tables
//        insertRow:  O(m), m is the number of columns
//        deleteRow:  O(1)
//        selectCell: O(m)
// Space: O(d), d is the total size of data

// hash table
class SQL {
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < size(names); ++i) {
            table_[names[i]].emplace_back(columns[i]);
        }
    }
    
    void insertRow(string name, vector<string> row) {
        row.emplace_back();  // soft delete
        table_[name].emplace_back(row);
    }
    
    void deleteRow(string name, int rowId) {
        table_[name][rowId].back() = "deleted";  // soft delete
    }
    
    string selectCell(string name, int rowId, int columnId) {
        return table_[name][rowId].back() != "deleted" ? table_[name][rowId][columnId - 1] : "";
    }

private:
    unordered_map<string, vector<vector<string>>> table_;
};
