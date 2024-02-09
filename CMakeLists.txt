cmake_minimum_required(VERSION 3.28.1)

project(calculator)

add_executable(${PROJECT_NAME} program.cpp calculator.cpp)

include_directories(sign)
add_subdirectory(sign)
include_directories(converter)
add_subdirectory(converter)
include_directories(validator)
add_subdirectory(validator)
include_directories(token)
add_subdirectory(token)
include_directories(analyzer)
add_subdirectory(analyzer)

add_library(signs program.cpp)

# signs
target_include_directories(${PROJECT_NAME} PUBLIC sign)
target_link_directories(${PROJECT_NAME} PRIVATE sign)
target_link_libraries(${PROJECT_NAME} 
    sign_base
    sign_pow
    sign_plus 
    sign_minus
    sign_mul
    sign_div
    signs_information
    signs_pointers
)

# converter
target_include_directories(${PROJECT_NAME} PUBLIC converter)
target_link_directories(${PROJECT_NAME} PRIVATE converter)
target_link_libraries(${PROJECT_NAME} 
    converter
)

# validator
target_include_directories(${PROJECT_NAME} PUBLIC validator)
target_link_directories(${PROJECT_NAME} PRIVATE validator)
target_link_libraries(${PROJECT_NAME} 
    validator
)

# analyzer
target_include_directories(${PROJECT_NAME} PUBLIC analyzer)
target_link_directories(${PROJECT_NAME} PRIVATE analyzer)
target_link_libraries(${PROJECT_NAME} 
    analyzer
)

# tokens
target_include_directories(${PROJECT_NAME} PUBLIC token)
target_link_directories(${PROJECT_NAME} PRIVATE token)
target_link_libraries(${PROJECT_NAME} 
    token_base
    token_sign
    token_number
    token_bracket
)
