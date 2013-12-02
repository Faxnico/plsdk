#!/bin/bash

set -e

source config.sh

builder="$1"
dir="$2"

cp $builder/subdir.mk $dir/jni/Android.mk
cp $builder/subdir.mk $dir/jni/external/Android.mk
cp $builder/Application.mk $dir/jni/Application.mk
cp $builder/envsetup.sh $dir/
cp $builder/README $dir/

exit 0
