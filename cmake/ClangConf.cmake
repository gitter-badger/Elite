SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
if (APPLE)
SET (CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
else()
SET (CMAKE_CXX_FLAGS "-std=c++11")
endif()
