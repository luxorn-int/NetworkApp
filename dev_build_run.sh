echo -e '\n'----- BUILDING PROJECT ----- 

cmake -DCMAKE_BUILD_TYPE=Debug -B "build/Debug"

cmake --build build/Debug

echo -e '\n'----- BUILDING ENDED ----- '\n'

echo -e '\n'----- RUNNING ----- 


./build/Debug/Tests/Debug/network_tests
