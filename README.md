# literate-bubble-sort

My attempt at writing CWEB (Literate Programming) for bubble sort visualizer.

Just run `make`, it will make a `sort.pdf` for the source documentation and `sort.c` 
with its executable `sort` that will run a bubble sort visualizer.

*Note:* You do have to install `cweave` and `ctangle` commands from [here](https://www-cs-faculty.stanford.edu/~knuth/cweb.html). And you would need a [(La)TeX](https://www.latex-project.org) installation to use `tex` and `dvipdft` commands for source generation. Your compiler (gcc) needs to have [ncurses](https://en.wikipedia.org/wiki/Ncurses) installed as well. Your favorite package manager should have it all.

This was a lot of fun to write. This readme is quite empty on purpose, so that
you could read more in `sort.pdf`
