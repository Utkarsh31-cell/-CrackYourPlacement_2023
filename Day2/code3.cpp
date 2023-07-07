//problem link :-> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/988477814/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0,cnt=0;
        vector<int>v;
        int n=prices.size();
       // maxi=prices[0];
        for(int i=1;i<n;i++){
           // maxi=max(maxi,prices[i]);
          v.push_back(prices[i]-prices[i-1]);
        }
        //since we hold stock hence we have to find max each time not in maximum subarray
        for(int i=0;i<v.size();i++){
            if(cnt+v[i]>=cnt){
                cnt+=v[i];
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
