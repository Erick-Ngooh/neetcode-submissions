class NumMatrix {
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int prefix;
        int above;
        sumMat = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
    
        for (int r = 0; r < row; r++) {
            prefix = 0;
            for (int c = 0; c < col; c++) {
                prefix += matrix[r][c];
                above = sumMat[r][c + 1];
                sumMat[r + 1][c + 1] = prefix + above;
            }
        }  
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, row2++, col1++, col2++;
        int bottomRight = sumMat[row2][col2];
        int above = sumMat[row1 - 1][col2];
        int left = sumMat[row2][col1 - 1];
        int topLeft = sumMat[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */