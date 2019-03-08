# qml2qcl/src/Makefile 


CPPFLAGS=-Wall -ggdb -g3
SRCS=$(wildcard *.cc)

OBJS=$(subst .cc,.o,$(SRCS))

.PHONY=all dep test


all:$(OBJS) qcl.hh
	$(MAKE) --directory=../ qcl2qml

include Makefile.dep

$(OBJS):$(SRCS)


# create dependency file Makefile.dep
dep:qcl.tab.c
	rm -f Makefile.dep
	g++ -MM $(SRCS) > Makefile.dep


LEX_YACC_OUTPUT=qcl.tab.c qcl.tab.h lex.qcl.c qcl.output
qcl.hh:$(LEX_YACC_OUTPUT)
qcl.tab.c: qcl.y qcl.l
	bison -d --report=all qcl.y
	flex  qcl.l

test:
	$(MAKE) --directory=../ test

clean:
	rm -f $(OBJS) $(LEX_YACC_OUTPUT)

