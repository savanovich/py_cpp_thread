.PHONY: run
run:
	(cd src/ && make setup && make pyrun)

.PHONY: clean
clean:
	(cd lib/ && make clean)
	(cd src/ && make clean)
