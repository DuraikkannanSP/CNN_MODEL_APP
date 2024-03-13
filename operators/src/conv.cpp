
#include "../include/conv.h"
#include "../include/relu.h"
std::vector<std::vector<std::vector<double>>> conv::convolution(
    const std::vector<std::vector<std::vector<double>>>& input,
    const std::vector<std::vector<std::vector<std::vector<double>>>>& kernel,
    int stride, int padding) {
    int input_height = input.size();
    int input_width = input[0].size();
    int input_channels = input[0][0].size();
    int kernel_height = kernel.size();
    int kernel_width = kernel[0].size();
    int output_channels = kernel[0][0][0].size();
    int output_height = (input_height - kernel_height + 2 * padding) / stride + 1;
    int output_width = (input_width - kernel_width + 2 * padding) / stride + 1;
    std::vector<std::vector<std::vector<double>>> result(
        output_height, std::vector<std::vector<double>>(
            output_width, std::vector<double>(output_channels, 0.0)
        )
    );
    for (int out_c = 0; out_c < output_channels; ++out_c) {
        for (int out_h = 0; out_h < output_height; ++out_h) {
            for (int out_w = 0; out_w < output_width; ++out_w) {
                double sum = 0.0;
                for (int k_h = 0; k_h < kernel_height; ++k_h) {
                    for (int k_w = 0; k_w < kernel_width; ++k_w) {
                        for (int in_c = 0; in_c < input_channels; ++in_c) {
                            int in_h = out_h * stride - padding + k_h;
                            int in_w = out_w * stride - padding + k_w;
                            if (in_h >= 0 && in_h < input_height && in_w >= 0 && in_w < input_width) {
                                sum += input[in_h][in_w][in_c] * kernel[k_h][k_w][in_c][out_c];
                            }
                        }
                    }
                }
                double after_relu=relu_layer::relu(sum);
                result[out_h][out_w][out_c] = after_relu;
            }
        }
    }
    return result;
}