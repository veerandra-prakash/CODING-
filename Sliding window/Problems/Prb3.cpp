Leetcode 2024

Maximize the Confusion of an Exam

QUESTION:

A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.



CODE:
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int final_len = INT_MIN,left=0,maxlen=0;
        unordered_map<char,int>mp;
        for(int right=0;right<answerKey.size();right++){
              mp[answerKey[right]]++;
              maxlen=max(maxlen,mp[answerKey[right]]);
              while((right-left+1) - maxlen>k){
                 mp[answerKey[left]]--;
                 if(mp[answerKey[left]]==0){
                    mp.erase(answerKey[left]);
                 }
                 left++;
              }
              final_len = max ( final_len  , right-left+1);
        }
      return final_len;
    }
};