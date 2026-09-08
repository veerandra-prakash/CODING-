1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

 

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

CODE:
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int final_count=0,left=0,sum=0,avg;
        for(int right=0;right<arr.size();right++){
            sum+=arr[right];
            avg=sum/k;
            if((right-left+1)==k){
                if(avg>=threshold){
                    final_count++;
                }
                sum-=arr[left];
                left++;
            }
        }
        return final_count;
    }
};