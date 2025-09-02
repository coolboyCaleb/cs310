#include <catch2/catch_all.hpp>
#include <catch2/catch_approx.hpp>
#include "math_functions.h"

TEST_CASE("Square root of positive numbers", "[math]") {
    REQUIRE(compute_sqrt(25.0) == 5.0);
    REQUIRE(compute_sqrt(0.0) == 0.0);
}

TEST_CASE("Square root of negative numbers", "[math]"){
    REQUIRE(compute_sqrt(-1.0) == -1.0);
}

TEST_CASE("Square root of a non-perfect square") {
    REQUIRE(compute_sqrt(2.0) == Catch::Approx(1.41421356237).epsilon(0.01));
}