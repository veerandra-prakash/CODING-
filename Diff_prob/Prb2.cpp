
1446. Consecutive Characters



The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.






CODE:

class Solution {
public:
    int maxPower(string s) {
        int max_len=INT_MIN,len=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                len++;
            }else{
                len=1;
            }
            max_len=max(max_len,len);
        }
        return s.size()==1 ? 1 : max_len;
    }
};
 

