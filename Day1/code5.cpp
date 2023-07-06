//problem:->https://leetcode.com/problems/find-the-duplicate-number/submissions/799127147/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,j=1;
        int ans=0;
        sort(nums.begin(),nums.end());
        while(i<=j){
            if(nums[i]==nums[j]){
                ans=nums[i];
                 break;
            }else{
               i++;
               j++;
            }
        }
        return ans;
    }
};
