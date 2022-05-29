redo-ifchange ../config.sh
. ../config.sh

redo-ifchange "${2}.o"

# Compile
${CC:-gcc} -c "../tests/${2}_test.c" ${CFLAGS} -MD -MF "${2}.test.d" -o "${2}.test.o"

# Depend on dependencies
read DEPS <"${2}.test.d"
redo-ifchange ${DEPS#*:}

# Additional obj files
OBJ="rmu.o"
redo-ifchange ${OBJ}

# Link
${CC:-gcc} ${OBJ} "${2}.test.o" ${LDFLAGS} -o "${3}"
