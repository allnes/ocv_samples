project( classification )
add_executable(${PROJECT_NAME} classification.cpp)

if( OpenCV_FOUND )
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
endif( OpenCV_FOUND )
