include $(BUILDER_HOME)/builder.mk

CFLAGS += -O2
LDFLAGS += -ldl
libs := libplepaper.a libpldraw.a libplinput.a
out := libplsdk.so

$(LIBDIR)/%.so:
	@echo "  LINK    " $(call relout,$@)
	@so=$(notdir $@)
ifeq ($(LANG),C++)
	@$(C++) $(CFLAGS) -fpic -shared -Wl,-soname,$(so) -o $@ -Wl,-whole-archive $^ -Wl,-no-whole-archive $(LDFLAGS)
else
	@$(CC) $(CFLAGS) -fpic -shared -Wl,-soname,$(so) -o $@ -Wl,-whole-archive $^ -Wl,-no-whole-archive $(LDFLAGS)
endif

target_out_lib = $(addprefix $(LIBDIR)/,$(out))
static_libs := $(addprefix $(LIBDIR)/,$(libs))

all: mkoutputdirs $(target_out_lib)
	@echo -n

$(target_out_lib): $(static_libs)
