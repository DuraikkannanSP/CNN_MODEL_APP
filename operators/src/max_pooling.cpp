#include "../include/max_pooling.h"
#include <limits>
std::vector<std::vector<std::vector<double>>> pooling_layer::max_pooling(
    const std::vector<std::vector<std::vector<double>>>& input,
    int pool_size, int stride) {
    int input_height = input.size();
    int input_width = input[0].size();
    int input_channels = input[0][0].size();
    int output_height = (input_height - pool_size) / stride + 1;
    int output_width = (input_width - pool_size) / stride + 1;
    std::vector<std::vector<std::vector<double>>> result(
        output_height, std::vector<std::vector<double>>(
            output_width, std::vector<double>(input_channels, 0.0)
        )
    );
    for (int c = 0; c < input_channels; ++c) {
        for (int out_h = 0; out_h < output_height; ++out_h) {
            for (int out_w = 0; out_w < output_width; ++out_w) {
                double max_val = std::numeric_limits<double>::lowest();
                for (int p_h = 0; p_h < pool_size; ++p_h) {
                    for (int p_w = 0; p_w < pool_size; ++p_w) {
                        int in_h = out_h * stride + p_h;
                        int in_w = out_w * stride + p_w;
                        if (in_h < input_height && in_w < input_width) {
                            max_val = std::max(max_val, input[in_h][in_w][c]);
                        }
                    }
                }
                result[out_h][out_w][c] = max_val;
            }
        }
    }
    return result;
}