test_targets_src = $(wildcard *_test.cpp)

test_targets = $(test_targets_src:%_test.cpp=%_test)
test_objects = $(test_targets_src:%_test.cpp=%_test.o)
src_objects  = $(test_targets_src:%_test.cpp=%.o)

.PHONY: all
all: $(test_targets)

.PHONY: clean
clean:
	rm -rf $(test_targets) $(test_objects) $(src_objects)

.PHONY: test
test: all
	for test_to_run in $(test_targets); do \
        ./$$test_to_run; \
    done

$(test_targets): $(test_objects) $(src_objects)
	$(CXX) -o $@ $^
