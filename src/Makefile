.PHONY: setup
setup: clean
	python setup.py build
	sudo python setup.py install

.PHONY: pyrun
pyrun:
	python -c "import twait; twait.start_io_thread()"

.PHONY: devrun
devrun: setup pyrun

.PHONY: clean
clean:
	rm -rf build/
