cmake_minimum_required(VERSION 2.8.8)

project(Deformation)
set( DEFORMATIONLIB "${PROJECT_NAME}-lib")
set( DEFORMATION_H "${CMAKE_SOURCE_DIR}/include/")
set( DEFORMATION_SRC "${CMAKE_SOURCE_DIR}/src/")
find_path(EIGEN_H Eigen)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -w")


file(GLOB Srcs "${DEFORMATION_SRC}/*.c*")
file(GLOB Hdrs "${DEFORMATION_H}/*.h" )
# Set your files and resources here


add_library(${DEFORMATIONLIB} ${Srcs} ${Hdrs})
find_package(Qt5 COMPONENTS Widgets REQUIRED QUIET)
qt5_use_modules(${DEFORMATIONLIB} Core Gui Widgets)
target_include_directories(${DEFORMATIONLIB} PRIVATE
    ${DEFORMATION_H}/
    ${EIGEN_H}
)

target_link_libraries(${DEFORMATIONLIB} ImatiSTLExtension-lib)
add_executable(example ${Srcs} ${Hdrs})
target_include_directories(example PRIVATE
    ${DEFORMATION_H}/
    ${EIGEN_H}
)
