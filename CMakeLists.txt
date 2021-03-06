﻿cmake_minimum_required(VERSION 2.8)
project(Elite)

SET (CMAKE_BUILD_TYPE Debug) # 默认构建Debug模式

if(UNIX)
	include(cmake/UnixLLVM.cmake) # 使用LLVM的CMake自动寻找功能
	# include(cmake/UnixGlib.cmake) # 使用Pkg-Config寻找Glibmm 不再依赖Glibmm
	include(cmake/ClangConf.cmake) # 使用clang编译
elseif(WIN32)
	set(LLVM_SDK_PATH "C:/program files(x86)/LLVM" CACHE PATH "PATH TO LLVM")
	set(LLVM_VERSION 3.6 CACHE STRING "LLVM version to use default 3.6")
	include(cmake/MSVCConf.cmake) # 使用MSVC编译
	#set (LLVM_SDK_PATH D:\\LLVM)
	include(cmake/WindowsLLVM.cmake) # 寻找LLVM
endif()



## 配置输出目录
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## include路径配置
include_directories(src extlib/include
    Lex/include 
    LR_Scanner/includes 
    RedApple/includes 
    Builder/include 
    MetaScriptRunner/include
    ExIconv/include
)

## 链接目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/extlib/lib)

OPTION(BUILD_ALL "构建全部项目 / Build all component together." ON)
OPTION(USE_DYNAMIC "使用动态库 / Build with dynamic libraries." OFF)

add_subdirectory(ExIconv)
add_subdirectory(Lex)
add_subdirectory(LR_Scanner)
add_subdirectory(RedApple)
add_subdirectory(MetaScriptRunner)
add_subdirectory(Builder)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(elite ${source_files})


if(UNIX)
	set (dl_lib_link dl)
endif()

target_link_libraries(elite builder meta red scanner lex oolua_d lua exiconv
						${LLVM_LIBS} ${dl_lib_link})

## 下载第三方库
include(cmake/ThirdPartyBuild.cmake)

include(cmake/Doxygen.cmake)


