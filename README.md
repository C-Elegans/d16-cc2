# D16 C- Compiler
This is a work in progress compiler for the [D16 cpu](https://github.com/C-Elegans/d16) defined in another project.
The compiler compiles a small subset of C, called C-, which is defined [here](http://www.cs.dartmouth.edu/~cs57/Project/C-%20Spec.pdf).

Currently the compiler parses the input file and builds an AST which it subsequently prints. Code generation will come soon.
## Building
Linux and OS X:

(Requires bison and flex)
```
./autogen.sh
./configure
make
make install
```
