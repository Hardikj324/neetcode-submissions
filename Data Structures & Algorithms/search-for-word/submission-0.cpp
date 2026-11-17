class Solution {
public:
    int n = 0;
    int m = 0;
    int l = 0;
    bool solver(vector<vector<char>>& board, string word,string temp,int i,int j,int w){
        if(temp.size()==l){
            return true;
        }

        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }

        if(board[i][j]!=word[w]){
            return false;
        }
    char t=board[i][j];
    board[i][j]='.';
        
    temp.push_back(t);
    bool down = solver(board,word,temp,i+1,j,w+1);
    temp.pop_back();

    temp.push_back(t);
    bool up = solver(board,word,temp,i-1,j,w+1);
    temp.pop_back();

    temp.push_back(t);
    bool right = solver(board,word,temp,i,j+1,w+1);
    temp.pop_back();

    temp.push_back(t);
    bool left = solver(board,word,temp,i,j-1,w+1);
    temp.pop_back();

    board[i][j]=t;
    return down || up || right || left;
}
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0){
            return false;
        }

        n = board.size();
        m = board[0].size();
        l = word.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( board[i][j]==word[0]){
                    if(solver(board,word,"",i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
