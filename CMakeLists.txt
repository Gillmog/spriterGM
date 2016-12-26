cmake_minimum_required( VERSION 3.4.0 )

project( spriterGM CXX )

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  # using Clang or AppleClang
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-sign-compare -Wno-reorder -Wno-unused-variable")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-sign-compare -Wno-reorder -Wno-unused-variable")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
endif()

include_directories(${CMAKE_SOURCE_DIR}/nlohmann-json)
add_subdirectory(${CMAKE_SOURCE_DIR}/tinyxml2)
add_subdirectory(${CMAKE_SOURCE_DIR}/pugixml)
add_subdirectory(${CMAKE_SOURCE_DIR}/spriterengine)

set( SOURCE_LIB 
	src/tinyxmlspriterfileelementwrapper.h
	src/tinyxmlspriterfileelementwrapper.cpp
	src/tinyxmlspriterfiledocumentwrapper.h
	src/tinyxmlspriterfiledocumentwrapper.cpp
	src/tinyxmlspriterfileattributewrapper.h
	src/tinyxmlspriterfileattributewrapper.cpp
	src/spriterGM.h
	src/spriterGM.cpp
	src/pugixmlspriterfileelementwrapper.h
	src/pugixmlspriterfileelementwrapper.cpp
	src/pugixmlspriterfiledocumentwrapper.h
	src/pugixmlspriterfiledocumentwrapper.cpp
	src/pugixmlspriterfileattributewrapper.h
	src/pugixmlspriterfileattributewrapper.cpp
	src/maindll.cpp
	src/maindll.h
	src/jsonspriterfileelementwrapper.h
	src/jsonspriterfileelementwrapper.cpp
	src/jsonspriterfiledocumentwrapper.h
	src/jsonspriterfiledocumentwrapper.cpp
	src/jsonspriterfileattributewrapper.h
	src/jsonspriterfileattributewrapper.cpp
	src/gmsoundobjectinforeference.h
	src/gmsoundobjectinforeference.cpp
	src/gmsoundfile.h
	src/gmsoundfile.cpp
	src/gmpointinstanceinfo.h
	src/gmpointinstanceinfo.cpp
	src/gmobjectfactory.h
	src/gmobjectfactory.cpp
	src/gmimagefile.h
	src/gmimagefile.cpp
	src/gmfilefactory.h
	src/gmfilefactory.cpp
	src/gmboxinstanceinfo.h
	src/gmboxinstanceinfo.cpp
	src/gmboneinstanceinfo.h
	src/gmboneinstanceinfo.cpp
	src/gmatlasfile.h
	src/gmatlasfile.cpp
	src/gmtriggerobjectinfo.h
	src/gmtriggerobjectinfo.cpp
)		

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library(spriterGM SHARED ${SOURCE_LIB})

target_link_libraries (spriterGM
    tinyxml2
    pugixml
    spriterengine)




