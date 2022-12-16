// With only STL swap algorithm
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

// With STL reverse algorithm
std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
{
    for (auto &row : image)
    {
        std::reverse(row.begin(), row.end());

        for (auto &el : row) el ^= 1;
    }

    return image;
}
