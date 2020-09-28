cmake_minimum_required(VERSION 3.12.2)

project(EmployeeManager)

set(CMAKE_CONFIGURATION_TYPES "Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(EmployeeManager
  Employee.cpp
  Employee.h
  EmployeeManager.cpp
)
# Preprocessor definitions
target_compile_definitions(EmployeeManager PRIVATE
  $<$<CONFIG:Release>:_UNICODE;NDEBUG;_CONSOLE>
)

# SDL check
target_compile_options(EmployeeManager PRIVATE
  "$<$<CONFIG:Release>:/sdl>"
)

# Minimal rebuild
if (MSVC)
  target_compile_options(EmployeeManager PRIVATE
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(EmployeeManager PRIVATE
    ""
  )
endif ()
