add_library(sign_base sign_base.cpp)
add_library(sign_plus sign_plus.cpp)
add_library(sign_minus sign_minus.cpp)
add_library(sign_mul sign_mul.cpp)
add_library(sign_div sign_div.cpp)
add_library(sign_pow sign_pow.cpp)
add_library(signs_information signs_information.cpp)
add_library(signs_pointers signs_pointers.cpp)

# это нужно для того, чтобы линковщик понял что sign_plus зависит от sign_base
target_link_libraries(sign_base signs_information)
target_link_libraries(sign_plus sign_base)
target_link_libraries(sign_minus sign_base)
target_link_libraries(sign_mul sign_base)
target_link_libraries(sign_div sign_base)
target_link_libraries(sign_pow sign_base)
target_link_libraries(signs_pointers
    sign_base
    sign_plus
    sign_minus
    sign_mul
    sign_div
    sign_pow
)
