CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pthread

SOURCES		= as_0_basic_thread.c as_1_array_threads.c as_2_numbers.c as_3_square.c
EXECUTABLES	= as_0_basic_thread as_1_array_threads as_2_numbers as_3_square

all: $(EXECUTABLES)

as_0_basic_thread: as_0_basic_thread.c
	$(CC) $(CFLAGS) -o $@ $<

as_1_array_threads: as_1_array_threads.c
	$(CC) $(CFLAGS) -o $@ $<

as_2_numbers: as_2_numbers.c
	$(CC) $(CFLAGS) -o $@ $<

as_3_square: as_3_square.c
	$(CC) $(CFLAGS) -o $@ $<

run_basic_thread: as_0_basic_thread
	./as_0_basic_thread

run_array_threads: as_1_array_threads
	./as_1_array_threads

run_numbers: as_2_numbers
	./as_2_numbers

run_square: as_3_square
	./as_3_square

clean:
	rm -f $(EXECUTABLES)

