bool canArrange(std::vector<int>& arr, int k)
{
    std::unordered_map<int,int> uMap;

    for (const int &el: arr)
        uMap[ (el % k + k) % k] ++;

    for (const int &el : arr)
    {
        int val = (el % k + k) % k;

        if (val == 0)
        {
            if (uMap[val] & 1) return false;
        }
        else
            if (uMap[val] != uMap[k-val]) return false;
    }

    return true;
}
