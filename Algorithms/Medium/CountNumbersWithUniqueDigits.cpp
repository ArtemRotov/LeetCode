int countNumbersWithUniqueDigits(int n)
{
    if (n == 0)
        return 1;

    int result  = 10;
    short factor = 9;
    int sum = factor;

    for(short i = 0; i < n - 1; ++i)
    {
        sum *= factor;
        factor--;
        result += sum;
    }

    return result;
}
