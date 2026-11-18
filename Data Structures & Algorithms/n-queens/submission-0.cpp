class Solution {
public:
    int m = 0;
    bool is_valid(vector<string> &temp,int i,int j){
        for(int x=0;x<m;x++){
            if(x!=j && temp[i][x]=='Q'){
                return false;
            }
        }
        for(int y=0;y<m;y++){
            if(y!=i && temp[y][j]=='Q'){
                return false;
            }
        }


    for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
    {
        if (temp[x][y] == 'Q')
            return false;
    }

    for (int x = i - 1, y = j + 1; x >= 0 && y < m; x--, y++)
    {
        if (temp[x][y] == 'Q')
            return false;
    }

    return true;
}

    void solver(vector<vector<string>>& board,vector<string>& temp,int row_no){
        if(row_no==m){
            board.push_back(temp);
            return ;
        }

        for(int i=0;i<m;i++){
            temp[row_no][i] = 'Q';

            if(is_valid(temp,row_no,i)){
                solver(board,temp,row_no+1);
            }
            temp[row_no][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        vector<vector<string>> board;
        vector<string> temp(n,string(n,'.'));
        solver(board,temp,0);
        return board;
    }
};
