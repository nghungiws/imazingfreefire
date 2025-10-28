# TrollFool Dynamic Library Makefile

CC = gcc
CFLAGS = -Wall -Wextra -fPIC -O2
LDFLAGS = -shared
TARGET = libtrollfool.dylib
SOURCES = trollfool.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = trollfool.h

# Default target
all: $(TARGET)

# Build the dynamic library
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Install the library (optional)
install: $(TARGET)
	cp $(TARGET) /usr/local/lib/
	cp $(HEADERS) /usr/local/include/

# Uninstall the library (optional)
uninstall:
	rm -f /usr/local/lib/$(TARGET)
	rm -f /usr/local/include/$(HEADERS)

# Show library information
info: $(TARGET)
	@echo "TrollFool Dynamic Library Information:"
	@echo "Target: $(TARGET)"
	@echo "Sources: $(SOURCES)"
	@echo "Headers: $(HEADERS)"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"

# Test the library
test: $(TARGET)
	@echo "Testing TrollFool library..."
	@echo "Library file exists: $(shell test -f $(TARGET) && echo "Yes" || echo "No")"
	@echo "Library size: $(shell test -f $(TARGET) && ls -lh $(TARGET) | awk '{print $$5}' || echo "N/A")"

.PHONY: all clean install uninstall info test