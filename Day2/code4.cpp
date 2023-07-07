//Problem link->https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/3073460/prefix-sum-number-theory-intuition-o-n-time-o-k-space/
/*Learning of the Day
Intuition
Approach is based on the idea of prefix sums and a bit of number theory. I have discussed both below.

How prefix sum helps:

Prefix sums help us in calculating sub-array sum of an array A, given the start index and end index of the sub-array. Please see below how:

Suppose an A array of size n, where the ith element is ai:

A = [a1, a2, a3, a4, a5, ..., am-1, am, am+1, ..., an-3, an-2, an-1]

The prefix sum array would be:

P = [p1, p2, p3, p4, p5, ..., pm-1, pm, pm+1, ..., pn-3, pn-2, pn-1]

Let's take a sub-array with start and end index as i & j, such that:

i <= j and Prefix sum of i = pi, Prefix sum of j = pj

|----------pi------->| i
|------------------------pj------>| j
[p1, p2, p3, ..., pi-1, pi, pi+1, ..., pj, pj+1, ... pn-2, pn-1]

Thus, if we want sum of all the elements in the sub-array from i to j
we can easily calculate it using (pj - pi) in O(1) time.

Why do we need number theory here?

We only need to understand about the modulus operator and few properties related to it.

If a number n is divisible by k, then the remainder should be 0, given k != 0.
or, n%k = 0

Now let's assume n = a - b, we can replace n in n % k, to get the following:
(a - b) % k = 0

There are few properties of modulus(%):

(a + b) % c = (a % c + b % c) % c
(a − b) % c = (a % c − b % c) % c
(a ∗ b) % c = (a % c ∗ b % c) % c
Following the above, we can re-write (a - b) % k = 0 as the below:

(a % k - b % k) % k = 0 = 0 % k

From the above we can say:
a % k - b % k = 0

or, a % k = b % k

Let's use both of the above observations to derive our approach.

Approach
Let say, the sum of sub-array from index i to j is S, where i < j. Given the prefix sum of the array, we have prefix sum of i is pi and prefix sum of j is pj.

Then we can say:

S = pj - pi

Now if S % k == 0, then the sum of sub-array index i to j is divisible by k and we increment the count by 1.

Let's replace S = pj - pi in S % k == 0,

(pj - pi) % k = 0 which implies (pj % k - pi % k) % k = 0 % k

or, pj % k - pi % k = 0 or pj % k = pi % k

Thus, we conclude that if we find the same modulus of prefix sum at i and j (i < j), then we can be sure that the sub-array sum from i to j is divisible by k.

Now, since there can be mutiple such prefix sums that repeat, we store the count of the prefix sum modulo k. Whenever, we find a repeating prefix sum we can increment the count by that number.

There are 2 gotchas here.

Gotcha#1
Since, we have negative numbers too the we must take some care when calculating the modulo of a negative number.

Lets say we are dividing -5 by 2, then there can be 2 case:

case 1: 
     -5 | 2
 (-) -6 | -3
 ---------- 
      1  as the remainder
case 2: 
     -5 | 2
 (-) -4 | -2
 ---------- 
     -1  as the remainder
Thus, we would miss a sub-arry if this negative remainder is not handled. As seen above, 1 and -1 differ by 2. We can handle this case by adding k to the negative remainder.

Gotcha#2

If the prefix sum at i is divisible by k, i.e. pi % k == 0, then the remainder would be 0 and the very first time 0 remainder would be encountered we would have the frequency as 0 and our final count would be short by 1.
Thus to handle this we set the frequency of remainder 0 as 1 at the begining.

Complexity
Time complexity: O(n)O(n)O(n). As we are only traversing the array once.

Space complexity: O(k)O(k)O(k). Since we are storing the frequencies of the remainders. Thus there can be k remainders when dividing a number by k(0, 1, 2, 3 ... k-1).

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //sliding windows 

        int n=nums.size();
        int sum=0,ans=0;
        //first do naive approach  it is O(n^2)  hence it gives TLE
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //       cnt+=nums[j];
        //         if(cnt%k==0){
        //          ans+=1;
        //         }
        //     }
        // }
        //  return ans;
        //Now we can do optimised approach
        vector<int>pref(n+1,0);
      
map<int,int>mp;
mp.insert({0,1});
//here we already add one remainder 0 as 1 because when last time pref[i]%k==0 we do not come again in loop so that pref[i]%k==0 is count as 1 because mp[pref[i]%k]++ is below our count and hence we add 0 as frequency 1 initially
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
            pref[i]=pref[i]%k;
            if(pref[i]<0){                 //to avoid negative remainder 
                 pref[i]+=k;                //update pref[i]
            }
            if(mp.find(pref[i])!=mp.end()){
                ans+=mp[pref[i]];
            }
             mp[pref[i]%k]++;
        }
         return ans;
    }
};
