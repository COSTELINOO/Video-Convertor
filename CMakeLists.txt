cmake_minimum_required(VERSION 3.10)
project(Video_convertor)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-w)
add_compile_definitions(SOURCE_ROOT=\"${CMAKE_SOURCE_DIR}\")

# Caile catre bibliotecile externe
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/buildTool/lib/SFML")
set(TGUI_ROOT "${CMAKE_SOURCE_DIR}/buildTool/lib/TGUI")

include_directories(${CMAKE_SOURCE_DIR}/sourceCode/include)
include_directories(${SFML_ROOT}/include)
include_directories(${TGUI_ROOT}/include)

link_directories(${SFML_ROOT}/lib)
link_directories(${TGUI_ROOT}/lib)

# Executabilul 
add_executable(Video_convertor
        sourceCode/src/main.cpp
        sourceCode/src/fereastra_principala.cpp
        sourceCode/src/fereastra_download_video.cpp
        sourceCode/src/fereastra_download_audio.cpp
        sourceCode/src/fereastra_webm_to_mp4.cpp
        sourceCode/src/fereastra_mp4_to_mp3.cpp
        sourceCode/src/fereastra_mp3_to_wav.cpp
        sourceCode/src/functionalitati.cpp
        sourceCode/src/functii_draw.cpp
        
)

target_link_libraries(Video_convertor
        tgui
        sfml-graphics
        sfml-window
        sfml-system
        opengl32 gdi32 winmm
)

add_custom_command(TARGET Video_convertor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SFML_ROOT}/bin/sfml-graphics-2.dll"
        "${SFML_ROOT}/bin/sfml-window-2.dll"
        "${SFML_ROOT}/bin/sfml-system-2.dll"
        "${TGUI_ROOT}/bin/tgui.dll"
        $<TARGET_FILE_DIR:Video_convertor>
)

add_custom_command(TARGET Video_convertor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/buildTool/assets"
        "$<TARGET_FILE_DIR:Video_convertor>/assets"
)
