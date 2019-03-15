cmake_minimum_required(VERSION 2.8.3)
project(openCV)

## 캐킨 빌드를 할 때 요구되는 구성요소 패키지이다.
## 의존성 패키지로 message_generation, std_msgs, roscpp이며 이 패키지들이 존재하지 않으면 빌드 도중에 에러가 난다.
find_package(catkin REQUIRED COMPONENTS 
 message_generation 
 std_msgs 
 roscpp
 cv_bridge
 sensor_msgs
 image_transport
 OpenCV
)


## 의존하는 메시지를 설정하는 옵션이다.
## std_msgs가 설치되어 있지 않다면 빌드 도중에 에러가 난다.
generate_messages(DEPENDENCIES std_msgs)

## 캐킨 패키지 옵션으로 라이브러리, 캐킨 빌드 의존성, 시스템 의존 패키지를 기술한다.
catkin_package(
LIBRARIES openCV
CATKIN_DEPENDS std_msgs roscpp
)

## 인클루드 디렉터리를 설정한다.
include_directories(${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

## topic_publisher 노드에 대한 빌드 옵션이다.
## 실행 파일, 타깃 링크 라이브러리, 추가 의존성 등을 설정한다.
add_executable(openCV_pub src/openCV_pub.cpp)
add_dependencies(openCV_pub ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(openCV_pub ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(openCV_sub src/openCV_sub.cpp)
add_dependencies(openCV_sub ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(openCV_sub ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(openCV_img src/openCV_img.cpp)
add_dependencies(openCV_img ${${PROJECT_NAME}_EXPORTED_TARGETS}
${catkin_EXPORTED_TARGETS})
target_link_libraries(openCV_img ${catkin_LIBRARIES} ${OpenCV_LIBS})