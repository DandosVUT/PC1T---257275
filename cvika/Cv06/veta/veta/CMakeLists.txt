# CMakeList.txt : CMake project for veta, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (veta "veta.cpp" "veta.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET veta PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
