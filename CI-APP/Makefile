# Makefile é um arquivo no qual os parâmetros de construção do projeto estão configurados.
# É criado manualmente (no nosso caso), pode ser personalizado de acordo com a nossa necessidade.
#
# Na linha de comando, dentro de "./CI-APP/", digite:
#
# make all: constrói o projeto;
#
# make run: executa (caso não ocorram erros de compilação) o executável, 
# presente em "./CI-APP/App/", nomeado como "CI-App.exe"
#
# make clean: Após estar construído, executado e testado, 
# podemos limpar os executável, e objetos em "./CI-APP/Obj/", "./CI-APP/Bin/" e "./CI-APP/Lib/"
#
# Definindo variaveis para automatizar o processo
# Estas variáveis são definidas de acordo com o escopo corrente, de trabalho.
CC = g++
APP = ./App
BIN = ./Bin
INCLUDE = ./Include
INCLUDE_EXTERNLIB = ./Include/ExternLib/MenuTemplate
INCLUDE_EXTERNFUNCTIONS = ./Include/ExternLib/MenuTemplate/ExternFunctions
LIB = ./Lib
OBJ = ./Obj
SRC = ./Src
FORM = Form
FLAGS = -std=c++11
# FLAGS = -O3 -Wall -std=c++11
CI-APP = CI-App.exe


# TAG 1
# Declaração do parâmetro "all" (aqui estão as bibliotecas 
# e aplicações a serem definidas como saída da compilação)
all: libutils libform libextern app


# TAG 2
# Gerando Biblioteca LibUtils.a (bibioteca estática). Esta biblioteca representa utilitários do projeto.
libutils:
	$(CC) -c $(SRC)/Help.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/Help.o
	$(CC) -c $(SRC)/PrintingModule.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/PrintingModule.o
	$(CC) -c $(SRC)/QAModule.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/QAModule.o
	$(CC) -c $(SRC)/Components.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/Components.o
	ar -rcs $(LIB)/LibUtils.a $(OBJ)/Help.o $(OBJ)/PrintingModule.o $(OBJ)/QAModule.o $(OBJ)/Components.o


# TAG 3
# Gerando Biblioteca LibForm.a (bibioteca estática). Esta biblioteca representa o formulário CRUD (Form) em nosso projeto.
libform:
	$(CC) -c $(SRC)/$(FORM)Create.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Create.o
	$(CC) -c $(SRC)/$(FORM)Select.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Select.o
	$(CC) -c $(SRC)/$(FORM)Update.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Update.o
	$(CC) -c $(SRC)/$(FORM)Delete.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Delete.o
	$(CC) -c $(SRC)/$(FORM)Data.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Data.o
	ar -rcs $(LIB)/LibForm.a $(OBJ)/$(FORM)Create.o $(OBJ)/$(FORM)Select.o $(OBJ)/$(FORM)Update.o $(OBJ)/$(FORM)Delete.o $(OBJ)/$(FORM)Data.o


# TAG 4
# Gerando Biblioteca LibExtern.a (bibioteca estática). Esta biblioteca representa o Menu (MenuTemplate externo) em nosso projeto.
libextern:
	$(CC) -c $(INCLUDE_EXTERNLIB)/MenuTemplate.cpp -I $(INCLUDE_EXTERNLIB) $(FLAGS) -o $(OBJ)/MenuTemplate.o
	$(CC) -c $(INCLUDE_EXTERNLIB)/Entry.cpp -I $(INCLUDE_EXTERNLIB) $(FLAGS) -o $(OBJ)/Entry.o
	$(CC) -c $(INCLUDE_EXTERNFUNCTIONS)/getChar.cpp -I $(INCLUDE_EXTERNFUNCTIONS) $(FLAGS) -o $(OBJ)/getChar.o
	ar -rcs $(LIB)/LibExtern.a $(OBJ)/MenuTemplate.o $(OBJ)/Entry.o $(OBJ)/getChar.o


# TAG 5
# Gerando executável (programa)
app:
	$(CC) $(APP)/CI-App.cpp $(LIB)/*.a -I $(INCLUDE) $(FLAGS) -o $(BIN)/$(CI-APP)


# TAG 6	
# Executa o programa (executável em ./CI-App/Bin/)
run:
	$(BIN)/$(CI-APP)


# TAG 7
# Limpa os arquivos objetos, bibliotecas e executáveis para um compilação "full".
clean:
	rm $(OBJ)/*.o
	rm $(LIB)/*.a
	rm $(BIN)/*.exe

