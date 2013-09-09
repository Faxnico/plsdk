include $(BUILDER_HOME)/builder.mk

lib_dirs := \
	pl-kernel-headers \
	python-headers \
	external/eglib \
	libplepaper \
	mod_plepaper \
	libpldraw \
	libplinput \
	libplhw \
	pyplsdk \
	plsdk \
	external/zlib \
	external/libpng \
	external/libjpeg \
	external/zlibmodule \
	external/pil

app_dirs := \
	eptest \
	epview \
	plinput \
	plottest \
	plhwtools

subdirs := $(lib_dirs) $(app_dirs)

.PHONY: all

all: print-arch sub-make
