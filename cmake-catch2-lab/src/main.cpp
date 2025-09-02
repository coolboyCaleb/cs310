#include "math_functions.h"
#include <iostream>

int main(){
    double num = 25.0;
    double result = compute_sqrt(num);
    std::cout << "Square root of " << num << " is " << result << std::endl;
    return 0;
}