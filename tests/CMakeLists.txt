find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${BASE_LOCATION}/source
                     ${Boost_INCLUDE_DIRS}
                     )
add_definitions (-DBOOST_TEST_DYN_LINK)
add_executable (Test test.cpp)
target_link_libraries (Test
                       Sqr
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                       )
add_test (NAME MyTest COMMAND Test)