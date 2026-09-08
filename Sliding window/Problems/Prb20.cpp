424. Longest Repeating Character Replacement


You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

CODE:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0 , maxlen=INT_MIN , ans= INT_MIN;
        unordered_map<char,int>freq;
        for(int right =0; right<s.size();right++){
              freq[s[right]]++;
              maxlen=max(maxlen,freq[s[right]]);
              while(((right-left+1) - maxlen) > k){
                 freq[s[left]]--;
                 if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                 left++;
              }
              ans=max(ans,right-left+1);
        }
        return ans;
    }
};