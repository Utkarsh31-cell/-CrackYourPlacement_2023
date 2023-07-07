//Problem link->https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/988522836/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        vector<int>dp(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            dp[nums[i]]+=1;
            if(dp[nums[i]]==2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
