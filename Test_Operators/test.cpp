#include "../utilities/include/read_data.h"
#include "../include/json.hpp"
using json = nlohmann::json;

std::vector<std::vector<std::vector<double>>> read_conv_test(std::string config,std::string key){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in read_conv_test" << std::endl;
        return {};
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: in read_conv_test" << e.what()<<"in read_conv_test" << std::endl;
        return {};
    }
    // Extract the nested arrays
    std::vector<std::vector<std::vector<double>>> output_data;
    try {
        output_data = config_json[key].get<std::vector<std::vector<std::vector<double>>>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting config_data from config.json: " << e.what() <<"in read_conv_test"<<std::endl;
        return {};
    }
    return output_data;
}
std::vector<double> read_dense_test(std::string config,std::string key){
    std::ifstream config_file(config);
    if (!config_file.is_open()) {
        std::cerr << "Error opening config.json in dense_test" << std::endl;
        return {};
    }
    json config_json;
    try {
        config_file >> config_json;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config.json: " << e.what()<<"in dense_test" << std::endl;
        return {};
    }
    // Extract the nested arrays
    std::vector<double> output_data;
    try {
        output_data = config_json[key].get<std::vector<double>>();
    } catch (const std::exception& e) {
        std::cerr << "Error extracting config_data from config.json: " << e.what()<<"in dense_test" << std::endl;
        return {};
    }
    return output_data;
    
}
int compare_dense(std::vector<double> output,std::vector<double> ref){
    int flag=1;
    for(int i=0;i<output.size();i++){
        double a=output[i];
        double b=ref[i];
        if (abs(a-b)>1e-5){
            std::cout<<a<<"\t"<<b<<"\n";
            flag=0;
            break;
        }
    }
    return flag;
}
int compare_conv_relu(std::vector<std::vector<std::vector<double>>> output,std::vector<std::vector<std::vector<double>>> ref){
    // std::cout<<output.size()<<"\t"<<output[0].size()<<"\t"<<output[0][0].size()<<"\n";
    int flag=1;
    // std::cout<<ref.size()<<"\t"<<ref[0].size()<<"\t"<<ref[0][0].size()<<"\n";
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            for(int k=0;k<output[0][0].size();k++){
                double a=output[i][j][k];
                double b=ref[i][j][k];
                
                if (abs(a-b)>1e-5){
                    std::cout<<a<<"\t"<<b<<"\n";
                    flag=0;
                    break;
                }
            }
            if (flag==0)
                break;
        }
        if (flag==0)
            break;
    }
    return flag;
}



int main(){
    int flag;
    for (int i=1;i<5;i++){
        read_data_conv("data/test/conv_test/test_"+std::to_string(i)+"_config.json");
        std::vector<std::vector<std::vector<double>>> ref_vector=read_conv_test("data/test/conv_test/test_"+std::to_string(i)+"_ref.json","output_values");
        std::vector<std::vector<std::vector<double>>> out_vector=read_conv_test("data/test/conv_test/test_output_"+std::to_string(i)+"_data.json","data");
        flag=compare_conv_relu(out_vector,ref_vector);
        if (flag==1)
            std::cout<<"test_case_conv_"+std::to_string(i)+"passed\n";
        else
            std::cout<<"test_case_conv_"+std::to_string(i)+"failed\n";
    }
    
    read_data_dense("data/test/dense_test/test_1_config.json",0);
    std::vector<double>ref_vector_t_1=read_dense_test("data/test/dense_test/test_1_ref.json","output_values");
    std::vector<double>out_vector_t_1=read_dense_test("data/test/dense_test/test_output_1_data.json","data");
    int flag_1=compare_dense(out_vector_t_1,ref_vector_t_1);
    if (flag_1==1)
        std::cout<<"test_case_dense_1_passed\n";
    else
        std::cout<<"test_case_dense_1_failed\n";


    read_data_dense("data/test/dense_test/test_2_config.json",1);
    std::vector<double>ref_vector_t_2=read_dense_test("data/test/dense_test/test_2_ref.json","output_values");
    std::vector<double>out_vector_t_2=read_dense_test("data/test/dense_test/test_output_2_data.json","data");
    int flag_2=compare_dense(out_vector_t_2,ref_vector_t_2);
    if (flag_2==1)
        std::cout<<"test_case_dense_2_passed\n";
    else
        std::cout<<"test_case_dense_2_failed\n";


    read_data_dense("data/test/dense_test/test_3_config.json",0);
    std::vector<double>ref_vector_t_3=read_dense_test("data/test/dense_test/test_3_ref.json","output_values");
    std::vector<double>out_vector_t_3=read_dense_test("data/test/dense_test/test_output_3_data.json","data");
    int flag_3=compare_dense(out_vector_t_3,ref_vector_t_3);
    if (flag_3==1)
        std::cout<<"test_case_dense_3_passed\n";
    else
        std::cout<<"test_case_dense_3_failed\n";


    read_data_dense("data/test/dense_test/test_4_config.json",1);
    std::vector<double>ref_vector_t_4=read_dense_test("data/test/dense_test/test_4_ref.json","output_values");
    std::vector<double>out_vector_t_4=read_dense_test("data/test/dense_test/test_output_4_data.json","data");
    int flag_4=compare_dense(out_vector_t_4,ref_vector_t_4);
    if (flag_4==1)
        std::cout<<"test_case_dense_4_passed\n";
    else
        std::cout<<"test_case_dense_4_failed\n";

}