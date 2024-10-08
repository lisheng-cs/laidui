# 最小版本设置
cmake_minimum_required(VERSION 3.25)
message("hello")
message(${CMAKE_VERSION})

# set list
set(LISTVALU a1 a2 a3)
message(${LISTVALU})
list(APPEND port p1 p2 p3)
message(${port})
list(LENGTH LISTVALU len)
message(${len})
list(APPEND LISTVALU a5)
message(${LISTVALU})

# 流程控制
# 1.if条件流程控制
# 2.loop循环流程控制
set(VARBOOL TRUE)

if(VARBOOL)
    message(TRUE)
else()
    message(FALSE)
endif()

foreach(VAR RANGE 3)
    message(${VAR})
endforeach()

set(MY_LISTS 1 2 3)

foreach(VAR IN LISTS MY_LISTS ITEMS 4 F)
    message(${VAR})
endforeach()

set(L1 one two three four)
set(L2 1 2 3 4 5)

foreach(num IN ZIP_LISTS L1 L2)
    message("word = ${num_0}, num = ${num_1}")
endforeach()
