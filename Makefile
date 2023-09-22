#!/usr/bin/env nix-shell
#!nix-shell -I nixpkgs=https://github.com/NixOS/nixpkgs/archive/nixos-23.05.tar.gz -p gcc gnumake python3 -i make

all: test

test: main
	./main | python3 debug.py

main: main.o
