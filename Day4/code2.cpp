//problem link -> https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        
        vector<int>newa;
        while((i<m) || (j<n)){
            if((i<m)&&(j<n)){
               
             if(nums1[i]<nums2[j]){
               //    cout<<nums1[i]<<" ";
                 newa.push_back(nums1[i]);
                 i++;
             }else{
                 //   cout<<nums2[j]<<" ";
                 newa.push_back(nums2[j]);
                 j++;
             }
            }else if((i<m)&&(j>=n)){
                 //  cout<<nums1[i]<<" ";
                newa.push_back(nums1[i]);
            i+=1;
            }else if((j<n)&&(i>=m)){
               //  cout<<nums2[j]<<" ";
                  newa.push_back(nums2[j]);
                j+=1;
            }
        }
        nums1.clear();
       int f=newa.size();
        cout<<f<<" ";
        for(i=0;i<f;i++){
         nums1.push_back(newa[i]);     
        }
    }
};
