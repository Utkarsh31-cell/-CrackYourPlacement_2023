//problem ->https://leetcode.com/problems/3sum/description/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        map<vector<int>,int>mp;
        for(int i=0;i<n-1;i++){
            vector<int>v;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else{
                 v.push_back(nums[i]);
                 v.push_back(nums[j]);
                 v.push_back(nums[k]);
                 mp[v]++;
                 v.clear();
                 j++;
                 k--;
                }
            }
        }
        for(auto it : mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};
