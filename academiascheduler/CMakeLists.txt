
project(scheduler)

set(HEDEAR_FILES Scheduler.h)
set(SOURCE_FILES Scheduler.cpp)

add_library(libscheduler STATIC ${SOURCE_FILES})
target_include_directories(libscheduler PUBLIC .)

add_executable(scheduler ${SOURCE_FILES} main.cpp)

target_link_libraries(scheduler libscheduler)
