//problem link ->https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int nr=0,nc=0,c=0,r=0;
        vector<int>ans;

        while(r<n && c<m){
        
            for(int i=c;i<m;i++){
                //cout<<r<<" "<<matrix[r][i]<<"-> ";
                ans.push_back(matrix[r][i]);
            }
            
            r+=1;
             
            for(int i=r;i<n;i++){
               // cout<<c<<" "<<matrix[i][m-1]<<"-> ";
                ans.push_back(matrix[i][m-1]);
            }
              
            m-=1;
              
        if(r<n){
            for(int i=m-1;i>=c;i--){
               // cout<<m-1<<" "<<matrix[n-1][i]<<"-> ";
               ans.push_back(matrix[n-1][i]);
            }
        }
            n-=1;
        
           if(c<m){
            for(int i=n-1;i>=r;i--){
                ans.push_back(matrix[i][c]);
            }
           }
            c+=1;
            
           
            
        }
        return ans;
    }
};
