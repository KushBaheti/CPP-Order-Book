project(src)

set(HEADER_FILES Order.h OrderBook.h)
set(SOURCE_FILES Order.cpp OrderBook.cpp)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
