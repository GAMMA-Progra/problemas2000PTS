.PHONY: run clean clean_all format disasm raw trace debug

CXX := g++
CXXFLAGS := -std=c++11 -g3 -O2 \
			-Wall -Wextra -Wpedantic \
			-Wdeprecated -Wunreachable-code -Wduplicated-branches \
			-Wduplicated-cond -Wswitch-enum \
			-Wundef -Wunused -Wshadow -Wredundant-decls \
			-Wdouble-promotion -Wfloat-equal -Wpointer-arith \
			-Wcast-qual -Wcast-align -Wold-style-cast -Wconversion -Wnarrowing \
			-Wvla -Wformat=2 -Wlogical-op -Wnull-dereference \
			-Woverloaded-virtual \
			-Werror=return-local-addr -Werror=return-type

LDFLAGS :=

INPUT := input.txt

TARGET := build/main
BUILDDIR := build

SRCS := main.cpp
OBJS := ${SRCS:%.cpp=${BUILDDIR}/%.o}


${TARGET}: ${OBJS}
	@ echo "Linking..."
	@ mkdir -p $(dir $@)
	@ ${CXX} ${LDFLAGS} $^ -o $@

${BUILDDIR}/%.o: %.cpp
	@ echo "Compiling ${<}..."
	@ mkdir -p $(dir $@)
	@ ${CXX} ${CXXFLAGS} -MD $< -c -o $@


run: ${TARGET} ${INPUT}
	@ ./${TARGET} < ${INPUT}

clean:
	rm -rf ${TARGET} ${OBJS} ${OBJS:.o=.d}

clean_all: clean
	rm -rf calls.strace compile_flags.txt

format:
	clang-format -i ${SRCS}

disasm: ${TARGET}
	@ objdump -dC -M intel $< | bat --style=plain --wrap=never -l asm

raw: ${TARGET}
	@ hexyl $< | bat --style=plain

trace: calls.strace
	@ # This 63 is for the first 63 lines in a tipical C++ glibc program
	@ tail --lines=+63 $^ | bat --style=plain --wrap=never -l strace

calls.strace: ${TARGET} ${INPUT}
	@ echo "Tracing..."
	@- strace -o $@ ./${TARGET} < ${INPUT}

debug: ${TARGET} ${INPUT}
	@ gdb ${TARGET} -q -ex 'start args < ${INPUT}'

compile_flags.txt: Makefile
	echo ${CXXFLAGS} | tr ' ' '\n' > $@


-include $(OBJS:.o=.d)
