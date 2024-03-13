#include "../include/softmax.h"
std::vector<double> softmax_layer::softmax(const std::vector<double>& input) {
    std::vector<double> result;
    double sum_exp = 0.0;
    
    // Calculate the sum of exponentials of input values
    for (double value : input) {
        sum_exp += std::exp(value);
    }
    
    // Compute softmax probabilities for each input value
    for (double value : input) {
        double prob = std::exp(value) / sum_exp;
        result.push_back(prob);
    }
    
    return result;
}