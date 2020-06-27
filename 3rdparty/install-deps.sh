#!/bin/sh

wget https://github.com/fmtlib/fmt/archive/6.2.1.tar.gz
wget https://github.com/ericniebler/range-v3/archive/0.10.0.tar.gz
mv 0.10.0.tar.gz ranges-v3.tar.gz
mv 6.2.1.tar.gz fmt.tar.gz
tar -xzf ranges-v3.tar.gz
tar -xzf fmt.tar.gz
mv fmt-6.2.1 fmt
mv range-v3-0.10.0 range-v3
rm ranges-v3.tar.gz
rm fmt.tar.gz