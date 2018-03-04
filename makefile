CC =gcc
CFLAGS =-I.
INCLUDE = int_to_string.h
OBJECTS = main.o int_to_string.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

Int: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS)
