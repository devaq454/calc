add_library(function_base function_base.cpp)
add_library(function_sin function_sin.cpp)
add_library(function_sqrt function_sqrt.cpp)
add_library(functions_information functions_information.cpp)
add_library(functions_pointers functions_pointers.cpp)

# это нужно для того, чтобы линковщик понял что sign_plus зависит от sign_base
target_link_libraries(function_sin function_base)
target_link_libraries(functions_information function_base)
target_link_libraries(functions_pointers
    function_base
    function_sin
    function_sqrt
)
