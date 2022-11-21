int findGCD(std::vector<int>& nums)
{
    int max = *(std::max_element(nums.begin(), nums.end()));
    int min = *(std::min_element(nums.begin(), nums.end()));
    int result = min;

    for(; result > 0; --result)
    {
        if (max % result == 0 && min % result == 0)
            break;
    }

    return result;
}
