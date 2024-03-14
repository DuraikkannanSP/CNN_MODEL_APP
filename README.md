# CNN_MODEL_APP
CNN model application

### Description:

This repository contains a CNN pipeline development.

### Contents:

operators: implementation of different operators used in CNN models.
conv.cpp: Implementation of convolutional operator.
relu.cpp: Implementation of rectified linear unit (ReLU) activation function.
max_pooling.cpp: Implementation of max pooling operator.
flattern.cpp: Implementation of flattening operator.
dense.cpp: Implementation of dense (fully connected) layer.
softmax.cpp: Implementation of softmax activation function.
utilities: Implementation of utility functions used in data processing and manipulation.

### Prerequisites

- C++ compiler (supporting C++11 or later)
- [JSON for Modern C++ library (nlohmann/json)](https://github.com/nlohmann/json) (included in `include/json.hpp`)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/DuraikkannanSP/CNN_MODEL_APP.git

### To Build the CNN app

1. Create a Build directory:
   ```bash
   mkdir build
2. get into the build directory:
   ```bash
   cd build
2. Run the CMakeLists:
   ```bash
   cmake ..
3. Build the cmake:
   ```bash
   make

### To run the app

Run the test executable to execute unit tests for the implemented operators:
    ```
  ./build/test```

Run the main executable to run the application:
    ```
    ./build/main```
