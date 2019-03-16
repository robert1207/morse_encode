cc = gcc
prom = MorseCodeTool
CFLAGS=-I ./include
deps = $(shell find ./include -name "*.h")
src = $(shell find ./src -name "*.c")
obj = $(src:%.c=%.o) 

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) $(CFLAGS) -c $< -o $@
	

clean:
	rm -rf $(obj) $(prom)
