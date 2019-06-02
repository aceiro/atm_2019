# Makefile is a file where the build parameters of the project are configured.
# It is created manually (in our case), can be customized according to our need.
#
# Na linha de comando, dentro de "./CI-APP/", digite:
#
# make all: build the complete project;
#
# make run: executes (if no compilation errors occur) the executable, 
# present in "./CI-APP/App/", as the name of "CI-App"
#
# make clean: After building the project and testing, 
# it cleans the executable and object files present in "./CI-APP/Obj/" and "./CI-APP/App/"
#
# Defining variables to automate processes
# These variables are defined according to current scope.
CC = g++
APP = ./App
BIN = ./Bin
INCLUDE = ./Include
LIB = ./Lib
OBJ = ./Obj
SRC = ./Src
FORM = Form
FLAGS = -O3 -Wall -std=c++11
CI-APP = CI-App.exe

# TAG 1
# Declaration of the "all" parameter (here are the libraries 
# and applications to be deinfidos as output of compuilação)
all: libutils libform app

# TAG 2
# Generating library LibUtils.a (static library). This library represents project utilities.
libutils: $(OBJ)/Menu.o $(OBJ)/Help.o $(OBJ)/PrintingModule.o $(OBJ)/QAModule.o $(OBJ)/Components.o
	ar -rcs $(LIB)/LibUtils.a $(OBJ)/*.o

# TAG 3
# Generating library LibForm.a (static library). This library represents the CRUD form used for the Project scope's.
libform: $(OBJ)/$(FORM)Create.o $(OBJ)/$(FORM)Update.o $(OBJ)/$(FORM)Select.o $(OBJ)/$(FORM)Delete.o $(OBJ)/$(FORM)TAD.o
	ar -rcs $(LIB)/LibForm.a $(OBJ)/*.o

# TAG 4
# Generating executable (program)
app: $(BIN)/$(CI-APP)


# Filter for compilation of Form objects
$(OBJ)/$(FORM)%.o: $(SRC)/$(FORM)%.cpp $(INCLUDE)/$(FORM).hpp
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -o $@

# Filter for compilation of Utilities objects
$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -o $@

# Filter for general compilation of the executable based on the two static libraries that were created for the project.
$(BIN)/%.exe: $(APP)/%.cpp
#	If I were the need, it could be compiled by passing the objects (g++ $< $(OBJ)/*.o -I $(INCLUDE) $(FLAGS) -o $@)
	$(CC) $< $(LIB)/LibUtils.a $(LIB)/LibForm.a -I $(INCLUDE) $(FLAGS) -o $@

# TAG 5	
# Run the program
run:
	$(BIN)/$(CI-APP)

# TAG 6
# Clen the objects and executable files.
clean:
	rm $(BIN)/*.exe
	rm $(OBJ)/*.o
	rm $(LIB)/*.a

