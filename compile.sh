rm -rf build
mkdir -p build
cd build
cmake ..
cmake --build .
cd ..

cp build/prett ${1-"$HOME/bin"}
