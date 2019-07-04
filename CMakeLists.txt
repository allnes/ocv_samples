cmake_minimum_required( VERSION 2.8 )

project( classification )

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

add_executable(${PROJECT_NAME} classification.cpp)

if( OpenCV_FOUND )
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
endif( OpenCV_FOUND )
