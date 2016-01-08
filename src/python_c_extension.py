#!/usr/bin/env python
from sys import path
path.append('..')
from twait import start_io_thread
from pythonlib.wrappers import main


if __name__ == '__main__':
    main(start_io_thread)
