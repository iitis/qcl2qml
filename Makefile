# qml2qcl/Makefile

CXX=g++
CPPFLAGS=-Wall -ggdb -Isrc -g3

SRCDIR=src
DOCDIR=doc/
OBJS=$(subst .cc,.o,$(wildcard $(SRCDIR)*.cc))
#OBJS=src/qcl.o

.PHONE=all $(SRCDIR) $(DOCDIR)

all:
	$(MAKE) --directory=$(SRCDIR)
	$(CXX) -o qcl2qml $(CPPFLAGS) qcl2qml.cc $(SRCDIR)/*.o

qcl2qml:$(OBJS)
	$(CXX) -o qcl2qml $(CPPFLAGS) qcl2qml.cc $(SRCDIR)/*.o

include Makefile.dep

run:qcl2qml
	cat test/test2.qcl |  ./qcl2qml


dep:
	$(MAKE) --directory=$(SRCDIR)
	$(CXX) -MM $(CPPFLAGS) qcl2qml.cc -MT qcl2qml > Makefile.dep

lexer:
	$(MAKE) --directory=$(SRCDIR) lexer

doc:
	$(MAKE) --directory=doc 

edit:
	emacs -nw qcl2qml.cc

test:
	./qcl2qml test/test.qcl >> test/test.qml

.PHONY:doc test debug lexer all
