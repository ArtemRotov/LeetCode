int secondHighest(std::string s)
{
    int max = -1;
    int preMax = -1;
    for (const char &ch : s)
    {
        if (ch >= '0' && ch <= '9')
        {
            int num = ch - '0';

            if (num > max)
            {
                preMax = max;
                max = num;
            }
            else if (num > preMax && num != max)
                preMax = num;
        }
    }

    return preMax;
}
