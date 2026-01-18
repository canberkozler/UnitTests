mdkir build
cd build
cmake ..
cmake --build . --config Debug
ctest -C Debug --output-on-failure 
ctest -C Debug -V