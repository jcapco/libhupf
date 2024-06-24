VPATH = ../src
.RECIPEPREFIX +=

print-%  : ; @echo $* = $($*)

#RM = del /f /q

CC = g++
#exclude empty.cpp
src = $(filter-out ../src/empty.cpp, $(wildcard ../src/*.cpp))

objdir=./release
dllfile=$(objdir)/libhupf.a
_obj1 = $(patsubst %.cpp,%.o,$(src))
obj = $(patsubst %.o,$(objdir)/%.o,$(notdir $(_obj1)))
libs = 

# needs apt-get install gcc-multilib g++-multilib
INCLUDES = -I../inc
CXXFLAGS=-DNDEBUG -DLIBHUPF_EXPORTS -O3 -g -s -flto -Wall -Wextra -m32 -Wno-unknown-pragmas -Wno-deprecated-declarations -Wno-parentheses -Wno-unused-function -fopenmp -std=c++11
# -std=c++98 

#link flags
LDFLAGS = -fno-use-linker-plugin -lstdc++

# rule to generate a dep file by using the C preprocessor
# (see man cpp for details on the -MM and -MT options)
# compiles .c to .o
# $@ = $(output)
# $< = $(input)
$(objdir)/%.o: %.cpp
  @echo "Compiling..."
  $(CC) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

libhupf: $(obj)
  @echo "Linking..."
  $(CC) $(CXXFLAGS) -Wno-maybe-uninitialized $(obj) -shared -o $(dllfile) $(LDFLAGS) $(libs) 
#-Wl,--verbose
#-Wno-maybe-uninitialized 
  
#.PHONY: clean, no padding with ifeq!!
clean:  
ifeq ($(OS), Windows_NT)
  del /f /q $(subst /,\,$(obj)) $(subst /,\,$(dllfile))
else
  rm -f $(obj) $(dllfile)
endif

