from distutils.core import setup, Extension
import sys

# binary_c must be installed. In this case, add libbinary_c.so to /usr/local/lib and run ldconfig as sudo

version = 3-(sys.version_info[0] < 3)
module_file = 'binary_c_python'+str(version)+'.c'

setup(
    name='binary_c',
    version='0.1',
    description='This is a python API for binary_c by Rob Izzard and collaborators',
    author='Jeff Andrews',
    author_email='andrews@physics.uoc.gr',
    license='',
    ext_modules=[Extension("binary_c",
                           [module_file],
                           libraries=["binary_c", "bfd", "binary_c_api"],
                           library_dirs = ['../src', './'],
                           )]  # binary_c must be loaded
    )
