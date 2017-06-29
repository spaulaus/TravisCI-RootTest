/// @file unittests.cpp
/// @brief
/// @author S. V. Paulauskas
/// @date June 29, 2017
/// @copyright Copyright (c) 2017 S. V. Paulauskas. 
/// @copyright All rights reserved. Released under the Creative Commons Attribution-ShareAlike 4.0 International License

#include "RootInterface.hpp"

#include <UnitTest++.h>

TEST (TestOpeningAFile){
    CHECK_THROW(RootInterface::get()->OpenFile("/a/file/to/nowhere"), std::invalid_argument);
    RootInterface::get()->OpenFile("./test.root");
}

int main(int argc, char **argv) {
    return UnitTest::RunAllTests();
}