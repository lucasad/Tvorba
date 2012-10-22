configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

SET(tvorba_SRCS
    commander.c
    main.cpp
    commander.c)

SET_SOURCE_FILES_PROPERTIES(commander.c
    PROPERTIES COMPILE_FLAGS -std=c99)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/include" )

ADD_EXECUTABLE(tvorba ${tvorba_SRCS})

INSTALL(TARGETS tvorba
        RUNTIME DESTINATION bin)
