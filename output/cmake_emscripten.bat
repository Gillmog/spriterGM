cmake -GNinja ../ -DCMAKE_TOOLCHAIN_FILE=c:/Emscripten/emscripten/1.35.0/cmake/Modules/Platform/Emscripten.cmake
ninja
emcc libspriterGM.so -o function.html
pause