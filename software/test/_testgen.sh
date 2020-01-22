#!/bin/bash
set -e

PROJ_FILE="micromouse.cproj"

C_GRN=$(echo -e "\033[32m")
C_DEF=$(echo -e "\033[0m")
TMP=$(mktemp -u)

cleanup() {
    rm -f "$TMP"
}
trap cleanup EXIT

cat <<EOF
# This file is auto-generated.
# Please do not change or commit.
#
# If you need to make changes please change testgen.sh instead.
# Generated on $(date)

C_GRN=\$(shell echo "\033[32m")
C_DEF=\$(shell echo "\033[0m")
OUTPUT=test
CFLAGS=$CFLAGS
EOF

rm -f tests.h
touch tests.h

make_identifier() {
    echo "$1" | sed -e "s|[^a-zA-Z0-9]|_|g"
}

touch "$TMP"
SOURCES=$(grep -E "^ +<Compile +Include=\"[^.]+\.test\.c\" */?>" "../$PROJ_FILE" | sed -e "s|^[^\"]*\"\([^\"]*\).*|\1|g" -e "s|\\\\|/|g" | while read file; do
    echo "${C_GRN}PRE$C_DEF $file" >&2
    gcc $CFLAGS -E -DMICROMOUSE_TEST_PREFIX="$(make_identifier "../$file")" -DMICROMOUSE_TEST_DETECT "../$file" >> "$TMP"
    echo "../$file"
done)

grep "@MICROMOUSESTART@" "$TMP" | grep "@MICROMOUSEEND@" | sed -e "s|.*@MICROMOUSESTART@\([^:]*\):\([^:]*\):\([^@]*\)@MICROMOUSEEND@.*|RUN_TEST(\1, \"\3\")|g" > tests.h
SOURCES="$(echo $SOURCES $(grep "@MICROMOUSESTART@" "$TMP" | grep "@MICROMOUSEEND@" | sed -e "s|.*@MICROMOUSESTART@\([^:]*\):\([^:]*\):\([^@]*\)@MICROMOUSEEND@.*|\2|g" | sed -e "s| *, *|\n|g" | sort | uniq | sed -e "s|^|../|"))"
rm -f "$TMP"

cat <<EOF
SOURCES=$SOURCES
OBJS=$(echo " $SOURCES " | sed -e "s| |  |g" | sed -e "s| ../\([^ ]*\)\.c | \1.o |g")
DEFS=$(echo " $SOURCES " | sed -e "s| |  |g" | sed -e "s| ../\([^ ]*\)\.c | \1.d |g")

.PHONY: all
all: \$(OUTPUT)

.PHONY: clean
clean:
	@for file in \$(OUTPUT) \$(OBJS) \$(DEFS) tests.h tests.o; do echo \$(C_GRN)RM\$(C_DEF) \$\$file; rm -f \$\$file; done

.PHONY: run
run: \$(OUTPUT)
	\$(info \$(C_GRN)RUN\$(C_DEF) \$^)
	@./\$^

.PHONY: debug
debug: \$(OUTPUT)
	\$(info \$(C_GRN)DBG\$(C_DEF) \$^)
	@gdb ./\$^

\$(OUTPUT): \$(OBJS) tests.o
	\$(info \$(C_GRN)LD\$(C_DEF) \$@)
	@\$(CC) \$(CFLAGS) -o \$@ \$^

tests.o: tests.c tests.h ../include/testing.h
	\$(info \$(C_GRN)CC\$(C_DEF) \$<)
	@\$(CC) \$(CFLAGS) -c -DMICROMOUSE_TEST_PREFIX="$(make_identifier "$file")" -o \$@ \$<

EOF

for file in $SOURCES; do
    cat <<EOF
$(echo $file | sed -e "s|^../||" -e "s|\.c|\.o|"): $file \$(shell ./quietcat.sh $(echo $file | sed -e "s|^../||" -e "s|\.c|\.d|"))
	\$(info \$(C_GRN)CC\$(C_DEF) \$<)
	@mkdir -p \$\$(dirname "\$@")
	@\$(CC) \$(CFLAGS) -c -MMD -DMICROMOUSE_TEST_PREFIX="$(make_identifier "$file")" -o \$@ \$<

EOF
done
