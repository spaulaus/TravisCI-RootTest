add_executable(unittest unittests.cpp ../source/RootInterface.cpp)
target_link_libraries(unittest ${ROOT_LIBRARIES} RooFit RooFitCore UnitTest++)