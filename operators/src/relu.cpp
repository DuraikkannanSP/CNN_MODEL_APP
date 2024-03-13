#include "../include/relu.h"
#include <algorithm>
double relu_layer::relu(double conv_val){
    return std::max(conv_val,0.0);
}