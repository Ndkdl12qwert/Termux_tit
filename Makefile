PREFIX ?= /data/data/com.termux/files/usr
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

CXX = clang++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic
LDFLAGS =

SRCS = src/main.cpp \
       src/command.cpp \
       src/adb.cpp \
       src/pm.cpp \
       src/utils.cpp

TARGET = tit

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

install: $(TARGET)
	install -Dm755 $(TARGET) $(BINDIR)/$(TARGET)
	install -Dm644 man/tit.1 $(MANDIR)/tit.1

clean:
	rm -f $(TARGET)

.PHONY: all install clean