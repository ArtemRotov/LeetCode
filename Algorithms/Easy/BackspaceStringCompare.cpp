bool backspaceCompare(std::string s, std::string t)
{
    short pos = 0;
    while ( (pos = s.find("#")) != std::string::npos)
    {
        if (pos == 0)
            s.erase(pos,1);
        else
            s.erase(pos-1,2);
    }

    while ( (pos = t.find("#")) != std::string::npos)
    {
        if (pos == 0)
            t.erase(pos,1);
        else
            t.erase(pos-1,2);
    }

    return (s == t);
}
