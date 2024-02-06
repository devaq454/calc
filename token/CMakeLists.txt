add_library(token_base token_base.cpp)
add_library(token_sign token_sign.cpp)
add_library(token_number token_number.cpp)

target_link_libraries(token_sign token_base)
target_link_libraries(token_number token_sign)
