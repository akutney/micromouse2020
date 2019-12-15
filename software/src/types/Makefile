src = $(wildcard *.c)
tests_src = $(wildcard *_test.c)
non_tests_src = $(patsubst %_test.c, ,$(src))

test_targets = $(tests_src:%_test.c=%_test)
test_objects = $(tests_src:%_test.c=%_test.o)

src_objects = $(src:%.c=%.o)
non_tests_objects = $(non_tests_src:%.c=%.o)

.PHONY: all
all: $(test_targets)

.PHONY: clean
clean:
	rm -rf $(test_targets) $(test_objects) $(non_tests_objects)

.PHONY: test
test: all
	for test_to_run in $(test_targets); do \
        ./$$test_to_run; \
    done

%_test : %_test.o $(non_tests_objects)
	$(CC) -o $@ $^
