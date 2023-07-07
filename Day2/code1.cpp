//problem :->https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/988430279/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
             int i=0,j=1,cnt=0;
              int n=nums.size();
              vector<int>unique;
              unique.push_back(nums[0]);
             while(i<j&&j<n){
                 if(nums[i]==nums[j]){
                     cnt+=1;
                    
                 }else{
                      unique.push_back(nums[j]);
                 }
                 i++;
                 j++;
             }
            nums.clear();
            for(i=0;i<unique.size();i++){
                nums.push_back(unique[i]);
            }

             return n-cnt; 
    }
};
