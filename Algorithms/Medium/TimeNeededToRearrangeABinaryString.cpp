int secondsToRemoveOccurrences(std::string s)
{
    int result = 0;
    bool flag = true;

    while(flag)
    {
        flag = false;

        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == '0' && s[i+1] == '1')
            {
                std::swap(s[i], s[i+1]);
                flag = true;
                ++i;
            }
        }

        result += flag;
    }

    return result;
}
