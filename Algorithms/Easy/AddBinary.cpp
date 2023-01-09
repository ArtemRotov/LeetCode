std::string addBinary(std::string a, std::string b)
{
    std::string result;

    int sum = 0;
    short i = a.length() - 1;
    short j = b.length() - 1;

    for ( ; i >= 0 || j >= 0 || sum; --i, --j)
    {
        sum = (i >= 0) ? sum + (a[i] - '0') : sum;
        sum = (j >= 0) ? sum + (b[j] - '0') : sum;

        result.append(std::to_string(sum % 2));
        sum = sum / 2;
    }

    std::reverse(result.begin(),result.end());

    return result;
}
