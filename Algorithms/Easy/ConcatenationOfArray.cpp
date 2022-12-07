// Modifying an old array
std::vector<int> getConcatenation(std::vector<int>& nums)
{
    short n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        nums.push_back(nums[i]);
    }

    return nums;
}

// Creating a new array
std::vector<int> getConcatenation(std::vector<int>& nums)
{
    short n = nums.size();
    std::vector<int> answer(n*2);

    for (int i = 0; i < nums.size(); ++i)
    {
         answer[i] = nums[i];
         answer[i+n] = nums[i];
    }
    return answer;
}

