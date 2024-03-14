#include "../../include/json.hpp"
#include "../../operators/include/conv.h"
#include "../../operators/include/max_pooling.h"
#include "../../operators/include/flattern.h"
#include "../../operators/include/dense.h"
#include "../include/read_data.h"

using json = nlohmann::json;

void read_data_conv(std::string config){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in read_data_conv" << std::endl;
        return ;
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<" in read_data_conv" << std::endl;
        return ;
    }
    // Extract the nested arrays
    int stride;
    std::string input;
    std::string output;
    std::string kernel;
    try {
        stride = config_json["strides"][0].get<int>();
        input=config_json["input_values"].get<std::string>();
        kernel=config_json["kernel_values"].get<std::string>();
        output=config_json["output_values"].get<std::string>();
        std::cout<<"\n layer name:"<<config_json["name"].get<std::string>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting config_data from config.json: " << e.what()<<" in read_data_conv" << std::endl;
        return ;
    }
    int padding = 0; // Set your desired padding value
    // Read input data from input.json
    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::cerr << "Error opening input.json in read_data_conv" << std::endl;
        return ;
    }
    json input_json;
    try {
        input_file >> input_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing input.json: " << e.what()<<"in read_data_conv" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::vector<std::vector<std::vector<double>>> input_data;
    try {
        input_data = input_json["data"].get<std::vector<std::vector<std::vector<double>>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from input.json: " << e.what()<<"in read_data_conv" << std::endl;
        return ;
    }
    // Read kernel values from kernel.json
    std::ifstream kernel_file(kernel);  // Corrected file name
    if (!kernel_file.is_open()) {
        std::cerr << "Error opening kernel.json in read_data_conv" << std::endl;
        return ;
    }
    json kernel_json;
    try {
        kernel_file >> kernel_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing kernel.json: " << e.what()<<"in read_data_conv" << std::endl;
        return ;
    }
    // Extract the nested arrays for kernel values
    std::vector<std::vector<std::vector<std::vector<double>>>> kernel_values;
    try {
        kernel_values = kernel_json["kernel_values"].get<std::vector<std::vector<std::vector<std::vector<double>>>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting kernel_values from kernel.json: " << e.what()<<"in read_data_conv" << std::endl;
        return ;
    }
    // Perform convolution
    std::vector<std::vector<std::vector<double>>> result = conv::convolution(input_data, kernel_values, stride, padding);
    // Store the results in output.json
    json output_json;
    output_json["data"] = result;
    std::ofstream output_file(output);  // Corrected file name
    output_file << std::setw(4) << output_json << std::endl;
    return;
}

void read_data_pool(std::string config){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in read_data_pool" << std::endl;
        return ;
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<"in read_data_pool" << std::endl;
        return ;
    }
    // Extract the nested arrays
    int stride;
    int pool;
    std::string input;
    std::string output;
    try {
        stride = config_json["strides"][0].get<int>();
        pool= config_json["pool_size"][0].get<int>();
        input=config_json["input_values"].get<std::string>();
        output=config_json["output_values"].get<std::string>();
        std::cout<<"\n layer name:"<<config_json["name"].get<std::string>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from config.json: " << e.what()<<"in read_data_pool" << std::endl;
        return ;
    }


    int padding = 0; // Set your desired padding value
    // Read input data from input.json
    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::cerr << "Error opening input.json in read_data_pool" << std::endl;
        return ;
    }
    json input_json;
    try {
        input_file >> input_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing input.json: " << e.what()<<"in read_data_pool" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::vector<std::vector<std::vector<double>>> input_data;
    try {
        input_data = input_json["data"].get<std::vector<std::vector<std::vector<double>>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from input.json: " << e.what()<<"in read_data_pool" << std::endl;
        return ;
    }
    std::vector<std::vector<std::vector<double>>> result = pooling_layer::max_pooling(input_data,pool,stride);
    json output_json;
    output_json["data"] = result;
    std::ofstream output_file(output);  // Corrected file name
    output_file << std::setw(4) << output_json << std::endl;
    return;
}
void read_data_flat(std::string config){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in read_data_flat" << std::endl;
        return ;
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<"in read_data_flat" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::string input;
    std::string output;
    try {
        input=config_json["input_values"].get<std::string>();
        output=config_json["output_values"].get<std::string>();
        std::cout<<"\n layer name:"<<config_json["name"].get<std::string>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from config.json: " << e.what() << std::endl;
        return ;
    }
    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::cerr << "Error opening config.json in read_data_flat" << std::endl;
        return ;
    }
    json input_json;
    try {
        input_file >> input_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<"in read_data_flat" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::vector<std::vector<std::vector<double>>> input_data;
    try {
        input_data = input_json["data"].get<std::vector<std::vector<std::vector<double>>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from input.json: " << e.what()<<"in read_data_flat" << std::endl;
        return ;
    }
    std::vector<double> result = flattern_layer::flattern(input_data);
    json output_json;
    output_json["data"] = result;
    std::ofstream output_file(output);  // Corrected file name
    output_file << std::setw(4) << output_json << std::endl;
    return;
}
void read_data_dense(std::string config,int flag){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in read_data_dense" << std::endl;
        return ;
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::string input;
    std::string output;
    std::string kernel;
    try {
        input=config_json["input_values"].get<std::string>();
        output=config_json["output_values"].get<std::string>();
        kernel=config_json["kernel_values"].get<std::string>();
        std::cout<<"\n layer name:"<<config_json["name"].get<std::string>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from config.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }

    std::ifstream input_file(input);
    if (!input_file.is_open()) {
        std::cerr << "Error opening input.json in read_data_dense" << std::endl;
        return ;
    }
    json input_json;
    try {
        input_file >> input_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing input.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }
    // Extract the nested arrays
    std::vector<double> input_data;
    try {
        input_data= input_json["data"].get<std::vector<double>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting input_data from input.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }
    // Read kernel values from kernel.json
    std::ifstream kernel_file(kernel);  // Corrected file name
    if (!kernel_file.is_open()) {
        std::cerr << "Error opening kernel.json in read_data_dense" << std::endl;
        return ;
    }
    json kernel_json;
    try {
        kernel_file >> kernel_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing kernel.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }
    // Extract the nested arrays for kernel values
    std::vector<std::vector<double>> kernel_values;
    try {
        kernel_values = kernel_json["kernel_values"].get<std::vector<std::vector<double>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting kernel_values from kernel.json: " << e.what()<<"in read_data_dense" << std::endl;
        return ;
    }
    std::vector<double> result;
    // Perform dense
    if (flag==0)
        result = dense_layer::dense(input_data, kernel_values);
    else
        result = dense_layer::dense_with_softmax(input_data, kernel_values);
    // Store the results in output.json
    json output_json;
    output_json["data"] = result;
    std::ofstream output_file(output);  // Corrected file name
    output_file << std::setw(4) << output_json << std::endl;
    return;
}