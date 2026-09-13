class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i<n ; i++){
            vector<int>temp(n);
            for(int j = 0; j<n ; j++){
                temp[(j-rowShift[i] +n)%n] = grid[i][j];
            }
            grid[i] = temp;
        }
        for(int j = 0 ; j<n ; j++){
            vector<int>temp(n);
            for(int i = 0 ; i<n;i++){
                temp[(i-colShift[j]+n)%n] = grid[i][j];
                
            }
            for(int i = 0; i<n ; i++){
                grid[i][j] = temp[i];
            }
        }
        return grid;
    }
};