// Without stl algorithms (except swap)
std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
{
    for (int i = 0; i < image.size(); ++i)
    {
        int n = image[i].size();
        for (int j = 0; j < n/2; ++j)
        {
            image[i][j] = (image[i][j] + 1) % 2;
            image[i][n - 1 - j] = (image[i][n - 1 - j] + 1) % 2;
            std::swap(image[i][j],image[i][n - 1 - j]);
        }
        if (n % 2 == 1)   image[i][n/2] = (image[i][n/2] + 1) % 2;
    }

    return image;
}
