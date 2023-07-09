//problem link :->https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0,sum=0;
        
        
         //O(n^2) has passed 87/93 cases
        //  for(int i=0;i<n;i++){
        //      sum=0;
        //      for(int j=i;j<n;j++){
        //          sum+=nums[j];
        //          //cout<<nums[j]<<" ";
        //          if(sum==k){
        //              count+=1;
        //          }
        //      }
       
        //      cout<<"\n";
        //  }
        //concept learning question 
        //we will use prefix array for storing prefix sum i.e sum from 0 to ith index of array
        //after this we check for index i=2 to i=4  we have sum from 0 to 2 and from 0 to 4 
        //so for 2 to 4 it is nothing but pref[4]-pref[2]
        //suppose it is k i.e pref[4]-pref[2]=k =>pref[4]-k=pref[2]
        //hence we store pref[4]-k if pref[2] when come then it is adds up which ensure sum k is exist so for storing this we use maps
         vector<int>pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
 map<int,int>mp;
 for(int i=1;i<=n;i++){
     if(pref[i]==k){
         count+=1;
     }
     if(mp.find(pref[i]-k)!=mp.end()){
         count+=mp[pref[i]-k];
     }
     mp[pref[i]]++;
 }
         return count;
    }
};
