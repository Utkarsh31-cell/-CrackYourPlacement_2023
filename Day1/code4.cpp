//problem link -> https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
//{ Driver Code Starts
//here in this problem we have to distribute array sum choclate among m people such that difference between maximum and minimum is minimum //in case of binary search we have to distibute thing n sum among m people such that difference between minimum and maximum is maximum
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long long int mini=INT_MAX;
        for(int i=0;i<=n-m;i++){
            
           long long int cnt=a[i+m-1]-a[i];
          // cout<<cnt<<" ";
            mini=min(mini,cnt);
            
        }
        return mini;
    
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*
1
6
11 13 7 5 13 12
4
output:
2
*/
