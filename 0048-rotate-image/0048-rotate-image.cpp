class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int sc = 0;
        int ec = c-1;
        while(sc<ec){
            for(int i=0;i<=r-1;i++)
            {
                swap(matrix[i][sc],matrix[i][ec]);
            }
            sc++;
            ec--;
        }
    }
};