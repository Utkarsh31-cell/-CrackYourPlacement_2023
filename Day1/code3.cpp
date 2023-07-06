//problem ->3 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//basically here on day 1 if he buy stock then later he will sell stock and then used kadane 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        vector<int>dp;
        for(int i=1;i<prices.size();i++){
            dp.push_back(prices[i]-prices[i-1]);
        }
        //maxsum kadane 
        int cnt=0,maxi=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]+cnt>dp[i]){
                cnt+=dp[i];
            }else{
                cnt=dp[i];
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
