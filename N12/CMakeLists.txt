cmake_minimum_required (VERSION 3.8)

project ("N12")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable (N12 "N12.cpp")
target_include_directories(N12 PUBLIC ${EIGEN3_INCLUDE_DIR})
target_link_libraries(N12 PUBLIC Eigen3::Eigen)