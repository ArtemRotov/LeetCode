std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if (strs.empty())
        return "";

    std::sort(strs.begin(), strs.end(), [&](const std::string &b, const std::string c)
                                            { return b.length() < c.length();});

    std::string result = strs[0];

    for (int i = 1; i < strs.size(); ++i)
    {
        if (strs[i].find(result) != 0)
        {
            result = result.substr(0,result.length()-1);
            i = 0;
        }
    }
    return result;
}
