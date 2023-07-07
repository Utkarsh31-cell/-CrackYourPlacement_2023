//https://leetcode.com/problems/two-sum/submissions/

//It is one of the two pointer problem  O(nlogn)    O(nlogn)->sorting and O(n) for finding target using two sum and we use vector pair to store original index of element
//This problem can also be solve using 2 for loop in O(n^2) naive approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vp;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],i});
        }
        int i=0,n=nums.size();
        int j=n-1;
        vector<int>ans;
        sort(vp.begin(),vp.end());
        while(i<=j){
            if(vp[i].first+vp[j].first==target){
               ans.push_back(vp[i].second);
               ans.push_back(vp[j].second);
               break;
            }else if(vp[i].first+vp[j].first>target){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
