#include "KLib/library.h"


...............................
include_directories(include)
include_directories(lib)

add_executable(engine main.cpp glad.c)

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/lib/glfw3.lib"
)

target_link_libraries(engine glfw)
.....................

link_directories(${CMAKE_SOURCE_DIR}/KLib)

add_library(KLib ../KLib/library.cpp)

target_link_libraries(Test PRIVATE KLib)
