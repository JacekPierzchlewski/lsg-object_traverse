# Makefile:  Makefile for C++ 'object traverse' example
#
# platforms:  Linux, Mac
# (c) Jacek Pierzchlewski, 2017  jacek@pierzchlewski.com
# license: BSD-2-Clause.


# Make cosniwa.o in the examples directory
cpp: object_traverse.cpp
	g++ -c object_traverse.cpp
	g++ object_traverse.o -lcosniwa -o object_traverse
