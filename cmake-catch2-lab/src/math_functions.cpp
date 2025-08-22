#include "math_functions.h"
#include <cmath>

double compute_sqrt(double number){
    if (number < 0){
        return -1;
    }
    else{
        return std::sqrt(number);
    }
};
