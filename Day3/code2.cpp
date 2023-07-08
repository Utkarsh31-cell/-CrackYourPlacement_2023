//problem link:-> https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<vector<int>,int>mp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //two pointer problem
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int k=j+1;
                int l=n-1;
                vector<int>v;
             
                while(k<l){
                       long long int total=0;
                       total+=nums[i];
                       total+=nums[j];
                       total+=nums[k];
                       total+=nums[l];
                    if(total>target){
                        l--;
                    }else if(total<target){
                        k++;
                    }else{
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        mp[v]++;
                        v.clear();
                        l--;
                        k++;
                    }
                }
            }
        }
        for(auto it : mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};
