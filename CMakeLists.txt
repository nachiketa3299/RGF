cmake_minimum_required(VERSION 3.27.0)
project(RGF
    VERSION 0.1.0
    DESCRIPTION "Simple Graphics Engine written by RZN"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    add_compile_options("/utf-8") # MSVC UTF-8 설정 (안하면 자꾸 뭐라고 함...)
endif()

# OpenGL 찾아서 포함
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# GLFW 찾아서 포함
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW Lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW Lib only")

add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)

# RDS 찾아서 포함
add_subdirectory(lib/rds)
include_directories(lib/rds/include)

# RFW 관련 설정
set(RFW_INC_DIR ${PROJECT_SOURCE_DIR}/include/)
set(RFW_SRC_DIR ${PROJECT_SOURCE_DIR}/src/)

set(RFW_CPP_SRCS main.cpp)
set(RFW_H_SRCS Application.h Object.h Window.h)

list(TRANSFORM RFW_H_SRCS PREPEND ${RFW_INC_DIR})
list(TRANSFORM RFW_CPP_SRCS PREPEND ${RFW_SRC_DIR})

set(RFW_SRCS ${RFW_CPP_SRCS} ${RFW_H_SRCS})

# 현재는 타겟이 하나라서 임시로 이렇게 해놓음
add_executable(${PROJECT_NAME} ${RFW_SRCS})

# 라이브러리랑 타겟을 링킹한다.
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES} glfw RDS)