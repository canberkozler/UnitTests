mdkir build
cd build
cmake ..
cmake --build . --config Debug
ctest -C Debug --output-on-failure 
ctest -C Debug -V

# This command doesn't run the tests; it only lists which tests CTest has seen.
ctest -C Debug -N 
# only even tests
ctest -C Debug -R even