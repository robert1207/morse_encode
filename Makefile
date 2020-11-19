cc = gcc
prom = morse-encode-and-decode
deps = $(shell find ./src -name "*.h")
src = $(shell find ./src -name "*.c")
obj = $(src:%.c=%.o) 

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -Wall -g -fPIC -shared -o $@ -c $<

clean:
	rm -rf $(obj) $(prom)

install:
	cp $(prom) /usr/local/bin

