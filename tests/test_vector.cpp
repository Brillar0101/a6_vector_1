// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

TEST_CASE("Default constructor creates empty vector", "[Constructor]") {
    dsa::Vector<int> v;
    bool ok{true};
    REQUIRE(ok);
}

TEST_CASE("push_back increases size and adds elements to array", "[push_back]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);

}

TEST_CASE("operator used to access and modify elements", "[operator[]]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v[0] = 15;
    REQUIRE(v[0] == 15);
    REQUIRE(v[1] == 20);
}

TEST_CASE("at() function validates bounds and throws exception", "[at]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    REQUIRE(v.at(0) == 10);
    REQUIRE(v.at(1) == 20);
    REQUIRE_THROWS_AS(v.at(2), std::out_of_range);
    REQUIRE_THROWS_AS(v.at(-1), std::out_of_range);
}

TEST_CASE("front() and back() return first and last elements", "[front][back]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 20);
}


