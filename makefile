.PHONY: all clean

all: rsa

rsa: ascii_to_text.c generate_keys.c main.c	large_numbers.c text_to_ascii.c
	gcc -Wall -pedantic -ansi ascii_to_text.c encrypt.c decrypt.c generate_keys.c large_numbers.c main.c text_to_ascii.c -o rsa	-lgmp -lm

clean:
	rm rsa.exe rsa
