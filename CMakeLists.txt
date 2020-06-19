CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ENABLE_TESTING()

SET(CMAKE_CXX_STANDARD 17)
if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
#	ADD_DEFINITIONS("-Wall -Wextra -Weffc++ -Werror")
endif()

ADD_SUBDIRECTORY(2out)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(tutorial)

ADD_CUSTOM_TARGET(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
