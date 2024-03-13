#include "../include/dense.h"
#include "../include/relu.h"
#include "../include/softmax.h"
std::vector<double> dense_layer::dense(std::vector<double> input_data,std::vector<std::vector<double>> kernel_values){
    int output_size=kernel_values[0].size();
    std::vector<double> result(output_size, 0.0);
    int biases=0.0;
    for (int i = 0; i < output_size; ++i) {
        double sum = 0.0;
        for (std::size_t j = 0; j < input_data.size(); ++j) {
            sum += input_data[j] * kernel_values[j][i];
        }
        double after_relu = relu_layer::relu(sum + biases);
        result[i] = after_relu;
    }

    return result;
}

std::vector<double> dense_layer::dense_with_softmax(std::vector<double> input_data,std::vector<std::vector<double>> kernel_values){
    int output_size=kernel_values[0].size();
    std::vector<double> result(output_size, 0.0);
    int biases=0.0;
    for (int i = 0; i < output_size; ++i) {
        double sum = 0.0;
        for (std::size_t j = 0; j < input_data.size(); ++j) {
            sum += input_data[j] * kernel_values[j][i];
        }
        result[i] = sum;
    }
    std::vector<double> probabilities = softmax_layer::softmax(result);
    return probabilities;
}