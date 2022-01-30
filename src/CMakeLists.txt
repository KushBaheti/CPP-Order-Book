project(src)

set(HEADER_FILES Order.h OrderDetails.h OrderBook.h MatchingEngine.h)
set(SOURCE_FILES Order.cpp OrderBook.cpp MatchingEngine.cpp)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})
