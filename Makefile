all: homie
.PHONY: all

homie: homie.c
	gcc  -Wno-attributes -Iinclude -o $@ $<

check:
	refinedc check homie.c

icheck:
	refinedc check homie.c -Iinclude

run:
	./homie

clean:
	rm -f homie
.PHONY: clean
