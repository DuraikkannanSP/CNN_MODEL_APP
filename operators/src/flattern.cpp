#include "../include/flattern.h"
std::vector<double> flattern_layer::flattern(const std::vector<std::vector<std::vector<double>>>& input){
    std::vector<double> result;
    for (const auto& vec2d : input) {
        for (const auto& vec1d : vec2d) {
            result.insert(result.end(), vec1d.begin(), vec1d.end());
        }
    }
    return result;
    
}