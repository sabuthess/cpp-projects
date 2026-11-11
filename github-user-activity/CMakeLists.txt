cmake_minimum_required(VERSION 3.16)
project(GithubUserActivity VERSION 1.0 LANGUAGES CXX)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CURL REQUIRED)

add_executable(github_user_activity src/main.cc)

target_include_directories(github_user_activity PRIVATE include)

target_link_libraries(github_user_activity
    PRIVATE
    curlpp
    CURL::libcurl
)
