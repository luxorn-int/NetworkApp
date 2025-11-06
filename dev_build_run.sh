echo -e '\n'----- BUILDING PROJECT ----- 

cmake -DCMAKE_BUILD_TYPE=Debug -B "build/Debug" -A x64

cmake --build build/Debug -j $1

echo -e '\n'----- BUILDING ENDED ----- '\n'

echo -e '\n'----- RUNNING ----- 


./build/Debug/Tests/Debug/network_tests
