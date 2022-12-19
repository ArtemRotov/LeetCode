int findLengthOfShortestSubarray(std::vector<int>& arr)
{
    int res = 0;

    int right = arr.size() - 1;
    for (; right > 0 && arr[right-1] <= arr[right]; --right);

    res = right;

    for (int left = 0; (left < right) && (left == 0 || arr[left - 1] <= arr[left]); ++left)
    {
        while(right < arr.size() && arr[right] < arr[left]) ++right;
        res = std::min(res, right - left - 1);
    }

    return res;
}
