#!/bin/bash

set -e

source config.sh

builder="$1"
dir="$2"

tar xzf $PKGDIR/fast-builder-$FAST_BUILDER_VER.tar.gz -C $dir
mv $dir/fast-builder-$FAST_BUILDER_VER $dir/fast-builder
cp $builder/Makefile $dir/
mkdir -p $dir/plsdk/libplsdk
cp $builder/libplsdk/Makefile $dir/plsdk/libplsdk/
cp $builder/envsetup.sh $dir/
cp $builder/native-envsetup.sh $dir/
cp $builder/README $dir/

exit 0
