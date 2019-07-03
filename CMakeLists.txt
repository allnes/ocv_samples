cmake_minimum_required( VERSION 2.8 )

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

add_subdirectory(classification)
add_subdirectory(detection)
