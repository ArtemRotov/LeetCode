/*
648. Replace Words

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor.
For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with
the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
*/

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence)
    {
        std::unordered_map<std::string, std::string> uMap {};

        for (const auto &el : dictionary)
            uMap[el] = el;

        for (int begin = 0; begin < sentence.length(); )
        {
            int end = sentence.find(' ', begin);
            if (end == std::string::npos)
                end = sentence.length();

            std::string str = "";
            for (int i = begin; i < end; ++i)
            {
                str.push_back(sentence[i]);
                if (uMap.count(str) > 0)
                {
                    sentence.replace(begin, end - begin, uMap[str]);
                    end = begin + uMap[str].length();
                    break;
                }
            }

            begin = end + 1;
        }

        return sentence;
    }
};
