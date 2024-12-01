# 指定 cmake 最小版本, 意指 cmake 版本小于指定版本则构建过程终止
cmake_minimum_required(VERSION 3.26)

# 语言环境配置 ###########################################################################################################

# 语言版本
set(CMAKE_C_STANDARD 17)

# 如果指定的语言版本不受支持, 则构建过程终止
set(CMAKE_C_STANDARD_REQUIRED True)

# 只弃用 ISO C++ 标准的编译器标志, 而不使用特定编译器的扩展
set(CMAKE_C_EXTENSIONS OFF)

if(UNIX)
    # 将 install_rpath 的设置应用在 build_rpath 上
    # 避免在开发期间出现动态库找不到的问题
    set(CMAKE_BUILD_WITH_INSTALL_RPATH True)
endif()

# 项目配置 ##############################################################################################################

# 项目名称和语言
project(glib-hello-test LANGUAGES C VERSION 1.0.0)

# 内部库
if(UNIX)
    # glib-2.0
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLIB REQUIRED glib-2.0)

    message(STATUS "GLIB_INCLUDE_DIRS:${GLIB_INCLUDE_DIRS}")
    message(STATUS "GLIB_LIBRARIES:${GLIB_LIBRARIES}")
endif()

if(WIN32)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

    message(STATUS "GTK3_INCLUDE_DIRS:${GTK3_INCLUDE_DIRS}")
    message(STATUS "GTK3_LIBRARY_DIRS:${GTK3_LIBRARY_DIRS}")
    message(STATUS "GTK3_LIBRARIES:${GTK3_LIBRARIES}")

    # windows 平台在编译时最好追追加链接库目录,否则动态库查找比较麻烦
    link_directories(${GTK3_LIBRARY_DIRS})
endif()

# 编译相关配置 ###########################################################################################################

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 包含全局头文件
include_directories(${CMAKE_SOURCE_DIR}/include
    ${GLIB_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}
)

# 生成测试
aux_source_directory(. SRCS_MAIN)
add_executable(${PROJECT_NAME} ${SRCS_MAIN})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${dist_dir}/test)

target_link_libraries(${PROJECT_NAME}
    ${GLIB_LIBRARIES}
)

if(UNIX)
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "\${ORIGIN}/../lib")
endif()
