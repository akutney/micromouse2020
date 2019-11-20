# Include directory above Eigen library
mkfile_path := "$(abspath .)"
export CXX := g++ -I $(mkfile_path)


TOPTARGETS := all test clean

SUBDIRS := $(wildcard */.)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	@echo $(lastword_)
	@echo $(mkfile_path)
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)