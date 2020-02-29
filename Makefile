cc = gcc
prom = morse-encode-and-decode
CFLAGS=-I ./include
deps = $(shell find ./include -name "*.h")
src = $(shell find ./src -name "*.c")
obj = $(src:%.c=%.so) 

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.so: %.c $(deps)
	$(cc) $(CFLAGS) -Wall -g -fPIC -shared -o $@ -c $<

clean:
	rm -rf $(obj) $(prom)

install:
	cp $(prom) /usr/local/bin