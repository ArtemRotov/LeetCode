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
                s[i] = '1';
                s[i+1] = '0';
                flag = true;
                ++i;
            }
        }

        if (flag)
            result++;
    }

    return result;
}
