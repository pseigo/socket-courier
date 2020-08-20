# Use clang if possible 
if command -v clang &> /dev/null; then
  echo "Detected clang on this system, setting CXX compiler to clang++"
  cmake -B bin -DCMAKE_BUILD_TYPE=DEBUG -DUSE_TLS=1 -DCMAKE_CXX_COMPILER=clang++
else
  cmake -B bin -DCMAKE_BUILD_TYPE=DEBUG -DUSE_TLS=1 
fi
