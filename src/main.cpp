#include "../utilities/include/read_data.h"

int main() {
    read_data_conv("configs/layer_1_config.json");
    read_data_pool("configs/layer_2_config.json");
    read_data_conv("configs/layer_3_config.json");
    read_data_pool("configs/layer_4_config.json");
    read_data_conv("configs/layer_5_config.json");
    read_data_flat("configs/layer_6_config.json");
    read_data_dense("configs/layer_7_config.json",0);
    read_data_dense("configs/layer_8_config.json",1);
    return 0;
}











