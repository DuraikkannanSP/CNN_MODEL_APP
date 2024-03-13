#include <vector>
class dense_layer{
    public:
        static std::vector<double> dense(std::vector<double> input_data,std::vector<std::vector<double>> kernel_values);
        static std::vector<double> dense_with_softmax(std::vector<double> input_data,std::vector<std::vector<double>> kernel_values);
};