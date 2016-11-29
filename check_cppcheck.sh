#!/bin/bash
dir="$(pwd)"
mkdir -p "result_cppcheck"
cppcheck --verbose -DA --enable=warning,style,information -I /usr/include/ BinaryExpression.cpp LiteralExpression.cpp Parser.cpp main.cpp > "${dir}/result_cppcheck/out.txt" 2> "${dir}/result_cppcheck/err.txt"
cd "${dir}"


