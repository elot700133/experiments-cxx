CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(example-c++)

#FIND_PACKAGE(LIBRARY)

INCLUDE_DIRECTORIES(
  ${LIBRARY_INCLUDE_DIR}
)

#ADD_SUBDIRECTORY(src)

SET(SOURCE 
main.cpp
)
SET(CMAKE_CXX_FLAGS "-pthread -g -std=c++0x")

#---------------------------------------------------------
ADD_EXECUTABLE(a.out ${SOURCE})

TARGET_LINK_LIBRARIES(a.out
  ${LIBRARY_LIBRARIES}
  ncurses
)
#---------------------------------------------------------
ADD_EXECUTABLE(bar_menu.out bar_menu.cpp)

TARGET_LINK_LIBRARIES(bar_menu.out
  ${LIBRARY_LIBRARIES}
  ncurses
)
#---------------------------------------------------------
ADD_EXECUTABLE(cooked_mode.out cooked_mode.cpp)

TARGET_LINK_LIBRARIES(cooked_mode.out
  ${LIBRARY_LIBRARIES}
  ncurses
)
#---------------------------------------------------------
ADD_EXECUTABLE(window.out window.cpp)

TARGET_LINK_LIBRARIES(window.out
  ${LIBRARY_LIBRARIES}
  ncurses
)
#---------------------------------------------------------
ADD_EXECUTABLE(acs_variables.out acs_variables.cpp)

TARGET_LINK_LIBRARIES(acs_variables.out
  ${LIBRARY_LIBRARIES}
  ncurses
)
#---------------------------------------------------------
ADD_EXECUTABLE(form.out form.cpp)

TARGET_LINK_LIBRARIES(form.out
  ${LIBRARY_LIBRARIES}
  ncurses
  form
)
