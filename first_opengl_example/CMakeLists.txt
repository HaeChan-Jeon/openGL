cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME first_opengl_example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WINDOW_NAME "First OpenGL Example")
set(WINDOW_WIDTH 960)
set(WINDOW_HEIGHT 540)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

include(Dependency.cmake)

# 명시적으로 Python 경로를 설정
set(Python3_EXECUTABLE "C:/Users/admin/AppData/Local/Programs/Python/Python313/python.exe")
set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})

# Python 경로를 확인
message(STATUS "Using Python executable: ${Python3_EXECUTABLE}")

# Python이 필요한 의존성을 처리
find_package(Python3 REQUIRED COMPONENTS Interpreter)
if (NOT Python3_FOUND)
    message(FATAL_ERROR "Python3 not found. Please check your Python installation.")
endif()

# cmake -Bbuild . -DCMAKE_BUILD_TYPE=[Debug|Release]
# cmake --build build --config Debug
# .\build\Debug\cmake_project_example.exe

# 우리 프로젝트에 include / lib 관련 옵션 추가
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
)

# CMAKE_CXX_FLAGS에 /utf-8 플래그 추가
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})