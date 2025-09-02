#include <catch2/catch_test_macros.hpp>
#include "math_functions.h"
#include <catch2/catch_approx.hpp>

TEST_CASE("Square root of positive numbers", "[math]") {
    REQUIRE(compute_sqrt(25.0) == 5.0);
    REQUIRE(compute_sqrt(0.0) == 0.0);
}

TEST_CASE("Square root of negative numbers", "[math]"){
    REQUIRE(compute_sqrt(-1.0) == -1.0)
}

TEST_CASE("Square root of a non-perfect square") {
    REQUIRE(compute_sqrt(2.0) == Catch2::Approx(1.41421356237).epsilon(0.001));
}