configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

SET(tvorba_SRCS
    node.cpp
    dht.cpp
    main.cpp)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include" )

ADD_EXECUTABLE(tvorba ${tvorba_SRCS})

INSTALL(TARGETS tvorba
        RUNTIME DESTINATION bin)
