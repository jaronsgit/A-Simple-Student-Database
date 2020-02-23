CC=g++         # the compiler
LIBS=-lm       # the libraries we will ref

databaseDriver: database.o driver.o
	$(CC) driver.o database.o -o databaseDriver -std=c++11 $(LIBS)

# Implicit pattern rule for compiling object files
%.o : %.cpp   # $< is the first dependancy and $@ is the target
	$(CC) -c $< -o -std=c++11 $@
   

# deletes all the object code files
clean:
	@rm -f *.o
	@rm databaseDriver
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
  
	@mv databaseDriver ~/bin

run:
	./databaseDriver