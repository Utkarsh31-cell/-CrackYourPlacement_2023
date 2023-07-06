//problem link ->https://leetcode.com/problems/set-matrix-zeroes/
//here it is complete solution in cpp, although we just needed class Solution for Leetcode.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //key point is we have to identify which element are already zero and which make new zeroes are need to be seperated
        //so we declare boolean array in which we  assigned 0 to 0 and remaining to 1
        int n=matrix.size();
        int m=matrix[0].size();
         vector<vector<int>>check(n,vector<int>(m,0));
         for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[i].size();j++){
                 if(matrix[i][j]!=0){
                    check[i][j]=1;
                 }
             }
         }
         for(int i=0;i<matrix.size();i++){
             int nr=i;
             int nc;
             for(int j=0;j<matrix[i].size();j++){
                 if(check[i][j]==0){
                    nc=j;
                 
                 for(int k=0;k<matrix.size();k++){
                     if(check[k][nc]!=0){
                         matrix[k][nc]=0;
                     }
                 }
                 for(int k=0;k<matrix[i].size();k++){
                     if(check[nr][k]!=0){
                         matrix[nr][k]=0;
                     }
                 }
                 }
             }
         }
         for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[i].size();j++){
                if(check[i][j]==0){
                    matrix[i][j]=0;
                }
             }
             
         }
    }
};
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    int a[n][m],i,j,cnt=0;
    vector<vector<int>>matrix(n,vector<int>(m,0));
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cin>>matrix[i][j];
      }
    }
    Solution cs;
    cs.setZeroes(matrix);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
  }
  return 0;
}
