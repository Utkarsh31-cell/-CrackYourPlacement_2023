//problem link :->https://leetcode.com/problems/reverse-pairs/
//best use of divide and conquer or merge sort 
/*
Pattern:- Whenever you face a question in which You want to compare the element to its right array You can do it by Merge Sort Algorithm. It is itself a Comparison algorithm from Divide and Conquer. Two pointers makes our task easy in which we want something to pick from right after choosing or fixing or left elment.

Generally to find pairs and do something with the pairs will take O(n^2) time because of generating all pairs or including two nested loops. But to make it to O(nlogn) in which you want to do some calculation on the pairs, You can use Merge Sort Divide and Conquer Algorithm.

😇 Similar Pattern Questions are:- Nut and Bolt, Lock and Key etc.
  */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void merge(vector<int>&a,int l,int mid,int r,int &cnt){
    int i=l;
    int j=mid+1;
    while(i<=mid){
        
        while(j<=r && a[i]>2*(long)a[j]){
            j++;
        }
        cnt+=(j-(mid+1));
        i++;
    }
    i=l;
    j=mid+1;
    vector<int>res(r-l+1);
     int indx=0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
           res[indx]=a[i];
        indx++;
           i++;
        }else{
             res[indx]=a[j];
        indx++;
            j++;
        }
    }
   
    while(i<=mid){
        res[indx]=a[i];
        indx++;
        i++;
    }
    while(j<=r){
         res[indx]=a[j];
        indx++;
        j++;
    }
    indx=0;
    for(i=l;i<=r;i++){
        a[i]=res[indx];
        indx++;
    }
    return ;
}
void mergesort(int l,int r,vector<int>&a,int &cnt){
    if(l>=r){
        return;
    }
    int mid=l + (r-l)/2;
    mergesort(l,mid,a,cnt);
    mergesort(mid+1,r,a,cnt);
    merge(a,l,mid,r,cnt);
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int i,j,cnt=0;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(0,n-1,a,cnt);
    cout<<cnt;
    return 0;
}
