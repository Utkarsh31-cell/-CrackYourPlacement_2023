//problem lnk ->https://leetcode.com/problems/majority-element/
/*
here we have to find element of the array whose frequency is more than n/2  :->frequency means count of that element
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto it : mp){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return count;
    }
};
