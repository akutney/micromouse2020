CFLAGS=-I../include -g

C_GRN=$(shell echo "\033[32m")
C_DEF=$(shell echo "\033[0m")

.PHONY: all
all: test.make
	@$(MAKE) -f $^ $@

.PHONY: clean
clean: test.make
	@$(MAKE) -f $^ $@
	$(info $(C_GRN)RM$(C_DEF) $^)
	@rm -f $^

%: test.make
	@test "x$@" = "xMakefile" || $(MAKE) -f $^ $@

.PHONY: test.make
test.make:
	$(info $(C_GRN)GEN$(C_DEF) test.make)
	@CFLAGS="$(CFLAGS)" ./testgen.sh > $@
