1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.



CODE:
class Solution {
public:
    int maxVowels(string s, int k) {
        int final_count=INT_MIN,left=0,cnt=0;
        for(int right=0 ; right<s.size();right++){
            if(s[right]=='a'|| s[right]=='e'|| s[right]=='i'|| s[right]=='o'|| s[right]=='u'){
                cnt++;
            }
              if((right-left+1)==k){
                final_count=max(final_count,cnt);
               if(s[left]=='a'|| s[left]=='e'|| s[left]=='i'|| s[left]=='o'|| s[left]=='u'){
                  cnt--;
               }
                left++;
            }
        }
        return final_count;
    }
};
