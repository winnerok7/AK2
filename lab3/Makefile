.PHONY: build

build:
	g++ ./lab_app.cpp -o lab_app

default_goal: build def 

.PHONY: def

def:
	./lab_app -l -h -v -V100

.PHONY: run

run:
	./lab_app -o

.DEFAULT_GOAL:=default_goal
