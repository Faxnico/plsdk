export BUILDER_HOME=$PWD/fast-builder
export TOP_DIR=$PWD
export PATH=$PWD/out/$(uname -m)/bin:$PATH
export LD_LIBRARY_PATH=$PWD/out/$(uname -m)/lib
unset ARCH
unset CROSS_COMPILE
