mkdir -p "result_clang"
make clean
scan-build -v -o "result_clang" make