//problem link-> https://leetcode.com/problems/move-zeroes/submissions/987653099/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt+=1;
            }else{
                v.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<v.size()){
                nums[i]=v[i];
            }else{
                nums[i]=0;
            }
        }
    }
};

