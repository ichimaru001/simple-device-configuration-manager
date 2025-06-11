# COMPILER AND FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# TARGET EXECUTABLE NAME
TARGET = device_manager

# SOURCE AND OBJECT FILES
SRCS = main.c device_config.c
OBJS = $(SRCS: .c=.o)

# DEFAULT TARGET
all: $(TARGET)

#LINKING THE EXECUTABLE
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# COMPILING OBJECT FILES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# CLEAN COMMAND - REMOVE BUILD FILES
clean:
	rm -f $(OBJS) $(TARGET)
