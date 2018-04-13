SHELL = /bin/sh

CC = gcc
CXX = g++

ifndef DEBUG
DEBUG = 0
endif

SRCDIR = .
PLATFORMDIR = $(SRCDIR)/..

ifeq ($(DEBUG), 0)
  BINDIR=$(PLATFORMDIR)/bin
  OBJDIR=$(PLATFORMDIR)/obj
  LIBDIR=$(PLATFORMDIR)/lib
  CPPFLAGS=
else
  BINDIR=$(PLATFORMDIR)/bind
  OBJDIR=$(PLATFORMDIR)/objd
  LIBDIR=$(PLATFORMDIR)/libd
  CPPFLAGS= 
endif

LIB_DIRS =

ALLLDFLAGS = $(LDFLAGS)

LIBS = 
	  
INCLUDE = -I$(SRCDIR)

OBJS_COMMON = \
	$(OBJDIR)/array.o

OBJS = \
	$(OBJS_COMMON) \
	$(OBJDIR)/example1.o \

EXEFILE=$(BINDIR)/example1

all: makeDirs $(EXEFILE)

makeDirs:
	@if [ ! -d $(PLATFORMDIR) ]; then \
		echo "Creating $(PLATFORMDIR)"; \
		mkdir $(PLATFORMDIR); \
	fi
	@if [ ! -d $(OBJDIR) ]; then \
		echo "Creating $(OBJDIR)"; \
		mkdir $(OBJDIR); \
	fi
	@if [ ! -d $(BINDIR) ]; then \
		echo "Creating $(BINDIR)"; \
		mkdir $(BINDIR); \
	fi
	@if [ ! -d $(LIBDIR) ]; then \
		echo "Creating $(LIBDIR)"; \
		mkdir $(LIBDIR); \
	fi

buildExes: $(EXEFILE)

compile: $(OBJS)

clean:
	@if [ -f $(EXEFILE) ]; then \
		echo "Removing $(EXEFILE)"; \
		rm -f $(EXEFILE); \
	fi
	@if [ -d $(BINDIR) ]; then \
		echo "Removing $(BINDIR)"; \
		rm -rf $(BINDIR); \
	fi
	@if [ -d $(OBJDIR) ]; then \
		echo "Removing $(OBJDIR)/*.o"; \
		rm -f $(OBJDIR)/*; \
	fi
	@if [ -d $(OBJDIR) ]; then \
		echo "Removing $(OBJDIR)"; \
		rm -rf $(OBJDIR); \
	fi
	@if [ -d $(LIBDIR) ]; then \
		echo "Removing $(LIBDIR)"; \
		rm -rf $(LIBDIR); \
	fi


$(EXEFILE): $(OBJS)
	$(CXX) $(LIB_DIRS) -o $(EXEFILE) $(OBJS) $(ALLLDFLAGS) $(LIBS)

$(OBJDIR)/example1.o: $(SRCDIR)/example1.cpp
	$(CXX) -c $(INCLUDE) $(CPPFLAGS) $(ALLLDFLAGS) $< -o $@
$(OBJDIR)/array.o: $(SRCDIR)/array.cpp $(SRCDIR)/array.hpp
	$(CXX) -c $(INCLUDE) $(CPPFLAGS) $(ALLLDFLAGS) $< -o $@
