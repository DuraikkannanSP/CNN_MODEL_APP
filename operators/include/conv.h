#include<vector>
class conv{
public:
    static std::vector<std::vector<std::vector<double>>> convolution(
    const std::vector<std::vector<std::vector<double>>>& input,
    const std::vector<std::vector<std::vector<std::vector<double>>>>& kernel,
    int stride, int padding);
};