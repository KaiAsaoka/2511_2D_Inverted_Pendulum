# Install script for directory: C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Project")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-src/matplotlibcpp.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake/matplotlib_cppTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake/matplotlib_cppTargets.cmake"
         "C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-build/CMakeFiles/Export/3f1ac978750cdcf3e610322786e2ec96/matplotlib_cppTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake/matplotlib_cppTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake/matplotlib_cppTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake" TYPE FILE FILES "C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-build/CMakeFiles/Export/3f1ac978750cdcf3e610322786e2ec96/matplotlib_cppTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/matplotlib_cpp/cmake" TYPE FILE FILES "C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-build/matplotlib_cppConfig.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/kasaoka/OneDrive - UBC/UBC Notes/Y4W2/ENPH 459/2511_2D_Inverted_Pendulum/pendulumControlESP32/external/build/_deps/matplotlibcpp-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
