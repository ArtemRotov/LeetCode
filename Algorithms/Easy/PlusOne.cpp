std::vector<int> plusOne(std::vector<int>& digits)
{
    if (digits.back() != 9)
    {
        digits.back() = digits.back() + 1;
        return digits;
    }
    else
    {
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if ( ++digits[i] != 10)
                return digits;
            else
                digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
    }

    return digits;
}
