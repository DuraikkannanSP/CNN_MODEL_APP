#include<vector>
class pooling_layer{
    public:
        static std::vector<std::vector<std::vector<double>>> max_pooling(const std::vector<std::vector<std::vector<double>>>& input,int pool_size, int stride);
};