project(src)

set(HEADER_FILES Order.h)
set(SOURCE_FILES Order.cpp)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
