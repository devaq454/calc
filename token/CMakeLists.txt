add_library(token_base token_base.cpp)
add_library(token_sign token_sign.cpp)
add_library(token_number token_number.cpp)
add_library(token_bracket token_bracket.cpp)

# for fictive return
target_link_libraries(token_sign token_base)
target_link_libraries(token_number token_sign)
target_link_libraries(token_bracket token_sign)
