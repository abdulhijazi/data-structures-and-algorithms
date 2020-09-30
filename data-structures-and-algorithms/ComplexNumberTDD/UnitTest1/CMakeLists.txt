cmake_minimum_required(VERSION 3.12.2)

project(UnitTest1)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_library(UnitTest1 SHARED
  targetver.h
  unittest1.cpp
)
# Additional include directories
set_property(TARGET UnitTest1
  APPEND PROPERTY INCLUDE_DIRECTORIES
  $<$<CONFIG:Debug>:
    "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\include">
  $<$<CONFIG:Release>:
    "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\include">
)

# Preprocessor definitions
target_compile_definitions(UnitTest1 PRIVATE
  $<$<CONFIG:Debug>:_UNICODE;_DEBUG>
  $<$<CONFIG:Release>:_UNICODE;NDEBUG>
)

# Minimal rebuild
if (MSVC)
  target_compile_options(UnitTest1 PRIVATE
    "$<$<CONFIG:Debug>:/Gm->"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(UnitTest1 PRIVATE
    ""
  )
endif ()

# Additional library directories
if (MSVC)
  target_link_options(UnitTest1 PRIVATE
    $<$<CONFIG:Debug>:
      /LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\lib">
    $<$<CONFIG:Release>:
      /LIBPATH:"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\lib">
  )
else ()
  target_link_options(UnitTest1 PRIVATE
    $<$<CONFIG:Debug>:
      -L"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\lib">
    $<$<CONFIG:Release>:
      -L"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\UnitTest\lib">
  )
endif ()
