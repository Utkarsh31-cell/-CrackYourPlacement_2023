//Problem Link ->https://leetcode.com/problems/container-with-most-water/submissions/988532169/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size();
        int j=n-1;
        int sum=0;
        int maxi=0;
        while(i<j){
            sum=min(height[j],height[i]);
            maxi=max(maxi,(j-i)*sum);
          //first find water in area as min(height of two side of container * distance between them is area)
          //after this index updation done according to ith height of container to jth container height and update index of minimum height container
            if(height[j]>height[i]){           
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
