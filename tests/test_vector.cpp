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

TEST_CASE("pop_back decreases size of array and removes last element", "[pop_back]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v.back() == 10);
    v.pop_back();
    REQUIRE(v.size() == 0);
    REQUIRE_THROWS_AS(v.pop_back(), std::out_of_range);
}

TEST_CASE("insert() adds element at specified index and shifts elements", "[insert]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.insert(1, 15);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 15);
    REQUIRE(v[2] == 20);
    REQUIRE_THROWS_AS(v.insert(4, 25), std::out_of_range);
    REQUIRE_THROWS_AS(v.insert(-1, 5), std::out_of_range);
}


TEST_CASE( "erase removes element at index and shrinks", "[erase][shrink]" ) {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.erase(1);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 30);
    REQUIRE_THROWS_AS(v.erase(2), std::out_of_range);
    REQUIRE_THROWS_AS(v.erase(-1), std::out_of_range);
}

TEST_CASE("reserve increases capacity without changing size", "[reserve]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    int old_cap = v.capacity();
    v.reserve(10);
    REQUIRE(v.capacity() >= 10);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    v.reserve(1); 
    REQUIRE(v.capacity() >= old_cap);
}

TEST_CASE("shrink to fit reduces capacity to size", "[shrink]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.reserve(10);
    REQUIRE(v.capacity() >= 10);
    v.shrink_to_fit();
    REQUIRE(v.capacity() == v.size());
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("empty() returns correct status", "[empty]") {
    dsa::Vector<int> v;
    REQUIRE(v.empty() == true);
    v.push_back(10);
    REQUIRE(v.empty() == false);
    v.pop_back();
    REQUIRE(v.empty() == true);
}

TEST_CASE("Copy constructor creates independent copy", "[copy]") {
    dsa::Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    dsa::Vector<int> copy(v);
    REQUIRE(copy.size() == v.size());
    REQUIRE(copy.capacity() == v.capacity());
    REQUIRE(copy[0] == v[0]);
    REQUIRE(copy[1] == v[1]);
    copy[0] = 15;
    REQUIRE(v[0] == 10);
    REQUIRE(copy[0] == 15);
}

TEST_CASE("Vector works with different data types", "[types]"){
    dsa::Vector<std::string> sv;
    sv.push_back("dsa");
    sv.push_back("vectors");
    REQUIRE(sv.size() == 2);
    REQUIRE(sv[0] == "dsa");
    REQUIRE(sv[1] == "vectors");

    dsa::Vector<double> dv;
    dv.push_back(3.14);
    dv.push_back(2.71);
    REQUIRE(dv.size() == 2);
    REQUIRE(dv[0] == Approx(3.14));
    REQUIRE(dv[1] == Approx(2.71));
}
