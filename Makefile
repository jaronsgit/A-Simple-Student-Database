# This is a Makefile comment
CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref

# Need object files Fib.o and FibDriver.o to create exe fibonacci 
databaseDriver: database.o driver.o
	$(CC) driver.o database.o -o databaseDriver $(LIBS)

# Implicit pattern rule for compiling object files
%.o : %.cpp   # $< is the first dependancy and $@ is the target
	$(CC) -c $< -o $@
   
# other rules; invoked by make clean etc 

# deletes all the object code files
clean:
	@rm -f *.o
	@rm databaseDriver
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
  
	@mv databaseDriver ~/bin

run:
	./databaseDriver