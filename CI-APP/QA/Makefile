# Makefile é um arquivo no qual os parâmetros de construção do projeto estão configurados.
# É criado manualmente (no nosso caso), pode ser personalizado de acordo com a nossa necessidade.
#
# Na linha de comando, dentro de "./QA/", digite:
#
# make all: constrói o projeto;
#
# make run: executa (caso não ocorram erros de compilação) o executável, 
# presente em "./QA/Test/", nomeado como "Tests.exe"
#
# make clean: Após estar construído, executado e testado, 
# podemos limpar os executável, e objetos em "./QA/Obj" e "./QA/Test" e "./QA/Lib"
#
# Definindo variaveis para automatizar o processo
# Estas variáveis são definidas de acordo com o escopo corrente, de trabalho.
CC = g++
Test = ./Test
BIN = ./Bin
INCLUDE = ../Include
INCLUDE_QA = ./Module
LIB = ./Lib
OBJ = ./Obj
SRC = ../Src
MODULE = ./Module
FORM = Form
FLAGS = -std=c++11
QATest = QATest.exe


# TAG 1
# Declaração do parâmetro "all" (aqui estão as bibliotecas 
# e aplicações a serem definidas como saída da compilação)
all: libutils libform libtest test


# TAG 2
# Gerando Biblioteca LibUtils.a (bibioteca estática). Esta biblioteca representa utilitários do projeto.
libutils:
	$(CC) -c $(SRC)/Help.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/Help.o
	$(CC) -c $(SRC)/PrintingModule.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/PrintingModule.o
	$(CC) -c $(SRC)/Components.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/Components.o
	ar -rcs $(LIB)/LibUtils.a $(OBJ)/Help.o $(OBJ)/PrintingModule.o $(OBJ)/Components.o


# TAG 3
# Gerando Biblioteca LibForm.a (bibioteca estática). Esta biblioteca representa o formulário CRUD (Form) em nosso projeto.
libform:
	$(CC) -c $(SRC)/$(FORM)Create.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Create.o
	$(CC) -c $(SRC)/$(FORM)Select.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Select.o
	$(CC) -c $(SRC)/$(FORM)Update.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Update.o
	$(CC) -c $(SRC)/$(FORM)Delete.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Delete.o
	$(CC) -c $(SRC)/$(FORM)Data.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)Data.o
	$(CC) -c $(SRC)/$(FORM)ToPrint.cpp -I $(INCLUDE) $(FLAGS) -o $(OBJ)/$(FORM)ToPrint.o
	ar -rcs $(LIB)/LibForm.a $(OBJ)/$(FORM)Create.o $(OBJ)/$(FORM)Select.o $(OBJ)/$(FORM)Update.o $(OBJ)/$(FORM)Delete.o $(OBJ)/$(FORM)Data.o $(OBJ)/$(FORM)ToPrint.o


# TAG 4
# Gerando Biblioteca LibTest.a (bibioteca estática). Esta biblioteca Módulo de Testes.
libtest:
	$(CC) -c $(INCLUDE_QA)/QAModule.cpp -I $(INCLUDE_QA) $(FLAGS) -o $(OBJ)/QAModule.o
	ar -rcs $(LIB)/LibTest.a $(OBJ)/QAModule.o


# TAG 5
# Gerando executável (programa)
test:
	$(CC) $(Test)/QATest.cpp $(LIB)/*.a -I $(INCLUDE_QA) $(FLAGS) -o $(BIN)/$(QATest)


# TAG 6	
# Executa o programa (executável em ./Test/Bin/)
run:
	$(BIN)/$(QATest)


# TAG 7
# Limpa os arquivos objetos, bibliotecas e executáveis para um compilação "full".
clean:
	rm $(OBJ)/*.o
	rm $(LIB)/*.a
	rm $(BIN)/*.exe

