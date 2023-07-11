//problem link ->https://leetcode.com/problems/word-search/
//new problem to me a lot of learning using dfs and backtracking -->we have to make yet another approach os bfs using queue on this problem.

class Solution {
public:
bool dfs(vector<vector<char>>&a,string word,int n,int m,int i,int j,vector<vector<int>>&vis,int ind){
   if(ind==word.size()){
       return true;
   }
   if((i>=n)||(i<0)||(j<0)||(j>=m)){
       return false;
   }
   if(a[i][j]==word[ind]&&vis[i][j]==0){
       vis[i][j]=1;
       //here we are checking 4 directions
       if(dfs(a,word,n,m,i+1,j,vis,ind+1)==true||dfs(a,word,n,m,i-1,j,vis,ind+1)==true||
       dfs(a,word,n,m,i,j+1,vis,ind+1)==true||dfs(a,word,n,m,i,j-1,vis,ind+1)==true){
           return true;
       }else{
           vis[i][j]=0;
           return false;
       }
    
   }
   return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int  n=board.size();
        int  m=board[0].size();
        bool ans=false;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    ans=ans|dfs(board,word,n,m,i,j,vis,0);
                    if(ans){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
