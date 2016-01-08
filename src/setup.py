from distutils.core import setup, Extension

setup(
    name='twait',
    ext_modules=[Extension("twait", ["twait_py.cpp", "../lib/twait.cpp"],
    language="c++",
    include_dirs=['../lib'],
    extra_compile_args=['-std=c++11',])],
)
