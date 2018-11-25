sources=$(wildcard *.c)
objs=$(sources:.c=.o)

all: server_app

server_app: $(objs)
	@echo "Building output binary.."
	$(CC) -o $@ $(objs)
%.o: %.c
	@echo "Compiling sources.."
	$(CC) -c $(sources)
%.d: %.c
	@echo -n  "Creating dependancies.."
	@echo $@
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,    \($*\)\.o[ :]*     ,    \1.o $@ :   ,   g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
clean:
	@rm -f server_app *.o *.d* *~ *\#
	@rm *~
	@echo "Clean done.."

-include $(sources:.c=.d)

