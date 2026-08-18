class Solution {
public:
    void dfs(vector<vector<char>> &ans,vector<vector<int>> &vis,int i, int j , int delrow[],int delcol[]){
        vis[i][j] = 1;
        int n = ans.size();
        int m = ans[0].size();
        for(int k  = 0 ; k < 4 ; k++){
            int nr = i + delrow[k];
            int nc= j + delcol[k];
            if(nr>=0 && nr < n && nc >=0 && nc < m && !vis[nr][nc] && ans[nr][nc] == 'O'){
                vis[nr][nc] = 1 ;
                dfs(ans,vis,nr,nc,delrow,delcol);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {0,-1,1,0};
        int delcol[] = {-1,0,0,1};
        vector<vector<char>> ans = board;
        vector<vector<int>> vis (n,vector<int>(m,0));
        for(int j = 0 ; j < m ; j++){
            if(!vis[0][j] && ans[0][j] == 'O'){
                dfs(ans,vis,0,j,delrow,delcol);
            }
            if(!vis[n-1][j] && ans[n-1][j] == 'O'){
                dfs(ans,vis,n-1,j,delrow,delcol);
            }
        }
       for(int i = 0 ; i < n; i++){
            if(!vis[i][0] && ans[i][0] == 'O'){
                dfs(ans,vis,i,0,delrow,delcol);
            }
            if(!vis[i][m-1] && ans[i][m-1] == 'O'){
                dfs(ans,vis,i,m-1,delrow,delcol);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 1){
                    ans[i][j] = 'O';
                }else ans[i][j] = 'X';
            }
        }
        board = ans;
    }

};