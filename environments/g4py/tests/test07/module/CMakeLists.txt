# - build test library

include_directories(
  ${PYTHON_INCLUDE_PATH}
  ${Boost_INCLUDE_DIRS}
)

link_directories(${Boost_LIBRARY_DIRS})

# library
set(_TARGET test07)
add_library(
  ${_TARGET} SHARED
  test07.cc
)

set_target_properties(${_TARGET} PROPERTIES PREFIX "")
set_target_properties(${_TARGET} PROPERTIES OUTPUT_NAME "test07")
set_target_properties(${_TARGET} PROPERTIES SUFFIX ".so")


target_link_libraries (${_TARGET} ${BOOST_PYTHON_LIB} ${PYTHON_LIBRARIES})

# install
install(TARGETS ${_TARGET} LIBRARY DESTINATION ${TEST_MODULES_INSTALL_DIR})
