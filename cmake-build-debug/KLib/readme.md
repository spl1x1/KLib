//cmake

include_directories(KLib)
link_directories(${CMAKE_SOURCE_DIR}/KLib)
target_link_libraries(untitled1 PRIVATE ${CMAKE_SOURCE_DIR}/KLib/libKLib.a)

//manual

#include "KLib/library.h"