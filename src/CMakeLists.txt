configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

SET(tvorba_SRCS
    main.cpp
    commander.c)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}" "${PROJECT_BINARY_DIR}/include" )

ADD_EXECUTABLE(tvorba ${tvorba_SRCS})

INSTALL(TARGETS tvorba
        RUNTIME DESTINATION bin)
