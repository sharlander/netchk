# variables

CC = gcc
OBJ = build/code.o build/errors.o build/lookup.o build/namelookup.o build/optionsout.o build/output.o build/portconnection.o
CFLAGS =
DEPS = src/inhead.h

# make

netchk: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

build/%.o: src/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# make install

install:
	install -m 0755 -o root -g root netchk /usr/bin/netchk
	install -m 0644 -o root -g root man/netchk.8 /usr/share/man/man8/netchk.8
	gzip /usr/share/man/man8/netchk.8
