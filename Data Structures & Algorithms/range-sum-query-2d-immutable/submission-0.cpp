class NumMatrix {
private:
    vector<vector<int>> prefix_;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        setPrefix(matrix);
    }
    
    void setPrefix(vector<vector<int>>& matrix) { 
        for (auto tab : matrix) {
            int total = 0;
            vector<int> temp;
            temp.push_back(total);
            for (auto num : tab) {
                total += num;
                temp.push_back(total);
            }
            prefix_.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int i = row1; i <= row2; i++) {
            sum += prefix_[i][col2 + 1] - prefix_[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */