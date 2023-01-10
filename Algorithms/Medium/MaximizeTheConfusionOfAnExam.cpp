/*
2024. Maximize the Confusion of an Exam
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse
the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an
integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
*/

class Solution {
public:
    int maxConsecutiveAnswers(std::string answerKey, int k)
    {
        int len = answerKey.length();
        int left = 0;
        int res = 0;
        int cnt = 0;

        // maximum substring of 'T' which contains k 'F'
        for(int i = 0; i < len; i++)
        {
            if (answerKey[i] == 'F') cnt++;

            while(cnt > k)
            {
                if(answerKey[left] == 'F') cnt--;
                left++;
            }

            res = std::max(i - left + 1, res);
        }

        // maximum  substring of 'F' which contains k 'T'
        cnt = 0;
        left = 0;

        for(int i = 0; i < len; i++)
        {
            if(answerKey[i] == 'T') cnt++;
            while(cnt > k)
            {
                if (answerKey[left] == 'T') cnt--;
                left++;
            }

            res = std::max(i - left + 1,res);
        }
        return res;
    }
};
