BIN_NAME = QamingFramework
BUILD_DIR = ./build
DOC_DIR = ./docs

.PHONY: all
all:
	make build
	make docs

.PHONY: build
build:
	make subsystem
	qmake -config debug
	make --file Makefile2 -j4 all

.PHONY: docs
docs:
	rm -rf $(DOC_DIR)/*
	cd $(DOC_DIR);\
	doxygen -g;\
	( cat Doxyfile ; echo "INPUT = ../"; echo "RECURSIVE = YES" ) | doxygen - 
	cd $(DOC_DIR)/latex;\
	latex refman.tex;\
	pdflatex refman.tex;

.PHONY: subsystem
subsystem:
	mkdir -p $(DOC_DIR);
	mkdir -p $(BUILD_DIR);

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: exec
exec:
	cd $(BUILD_DIR) && ./$(BIN_NAME)
