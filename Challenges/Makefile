.PHONY: all compile build clean distclean run help

BUILDdir=BUILD
BINDIR=bin
RUNCMD=$(BINDIR)/mainMesh

all: compile

compile: build
	@ cd BUILDdir && $(MAKE) all

build: $(BUILDdir)/build

$(BUILDdir)/build: CMakeLists.txt ./**/CMakeLists.txt
	@ ln -s -f ../Examples/include/ include2
	@ ln -s -f ../Examples/lib/ lib2
	@ mkdir -p $(BUILDdir)
	@ echo "Running cmake..."
	@ cd $(BUILDdir) && cmake ..
	@ touch $(BUILDdir)/build

clean:
	@ if [ -d $(BUILDdir) ]; then \
		cd $(BUILDdir); \
		$(MAKE) clean; \
	fi

distclean: clean
	@ echo "Removing building directory..."
	@ $(RM) -r -f $(BUILDdir)/

run:
	$(RUNCMD)

help:
	@ echo "List of available targets:
	@ echo "all -> compile (default target)
	@ echo "build (building directory and makefiles)"
	@ echo "compile"
	@ echo "clean"
	@ echo "distclean"
