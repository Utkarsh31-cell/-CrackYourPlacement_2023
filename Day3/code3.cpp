//problem link:->https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,maxi=0;
        //two pointer
        int n=cardPoints.size();
        vector<int>pref(n+1,0);
        vector<int>suff(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+cardPoints[i-1];
        }
        for(int i=n-1;i>=0;i--){
           suff[i]=suff[i+1]+cardPoints[i];
        }
        for(int i=0;i<=k;i++){
          //maxi=max(maxi,pref[i]);
          //maxi=max(maxi,suff[n-i]);
          maxi=max(maxi,pref[i]+suff[n-k+i]);//basically we are doing  i=()0,k)summ(i)+summ(n-k+i)
          //maxi=max(maxi,pref[i]+cardPoints[n-i]-cardPoints[i-1]);
          //maxi=max(maxi,suff[n-i]-cardPoints[n-i]+cardPoints[i-1]);
        }
        return maxi;
    }
};
