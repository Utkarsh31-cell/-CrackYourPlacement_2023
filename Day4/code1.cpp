//problem link->https://leetcode.com/problems/jump-game/
/*
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Basically when you read this question you have just one thought come in mind i.e. when does we are unable to move.It is the index when nums[i] is 0 if i is for iterating from 0 to n-1.

# Approach
<!-- Describe your approach to solving the problem. -->
if n is 1 then return true because we are already on end point.
take a variable cnt in which hold value , upto which index we can reach from current index. 
if cnt is less than or equal to current index, and current index is   not 0, while current index element is 0 and and prevous index element is less than equal to 1 i.e. {we are unable to move more than current index }and cnt 
is not n-1, then it is false.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n), since we use single loop from 0 to n.
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
space complexity of our solution is also O(n) 
# Code
```%/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(n==1){
            return true;
        }
        for(int i=0;i<n;i++){
           
            cnt=max(cnt,i+nums[i]);
            
             if((i>0)&&(nums[i]==0)&&(nums[i-1]<=1)&&(cnt<=i&&cnt!=n-1)){
                 return false;
             }else if(i==0&&nums[i]==0){
                 return 0;
             }
            
             
        }
        
            return true;
        
    }
};
