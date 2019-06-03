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
LIB = ./Lib
OBJ = ./Obj
SRC = ./Src
FORM = Form
FLAGS = -O3 -Wall -std=c++11
CI-APP = CI-App.exe

# TAG 1
# Declaração do parâmetro "all" (aqui estão as bibliotecas 
# e aplicações a serem definidas como saída da compilação)
all: libutils libform app

# TAG 2
# Gerando Biblioteca LibUtils.a (bibioteca estática). Esta biblioteca representa utilitários do projeto.
libutils: $(OBJ)/Menu.o $(OBJ)/Help.o $(OBJ)/PrintingModule.o $(OBJ)/QAModule.o $(OBJ)/Components.o
	ar -rcs $(LIB)/LibUtils.a $(OBJ)/*.o

# TAG 3
# Gerando Biblioteca LibForm.a (bibioteca estática). Esta biblioteca representa o formulário CRUD (Form) em nosso projeto.
libform: $(OBJ)/$(FORM)Create.o $(OBJ)/$(FORM)Update.o $(OBJ)/$(FORM)Select.o $(OBJ)/$(FORM)Delete.o $(OBJ)/$(FORM)TAD.o
	ar -rcs $(LIB)/LibForm.a $(OBJ)/*.o

# TAG 4
# Gerando executável (programa)
app: $(BIN)/$(CI-APP)


# Filtro para compilação dos Forms (gerando objetos)
$(OBJ)/$(FORM)%.o: $(SRC)/$(FORM)%.cpp $(INCLUDE)/$(FORM).hpp
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -o $@

# Filtro para compilação dos Utilitários (gerando objetos)
$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	$(CC) -c $< -I $(INCLUDE) $(FLAGS) -o $@

# Filtro para compilação geral do executável com base nas duas bibliotecas estáticas que foram criadas para o projeto.
$(BIN)/%.exe: $(APP)/%.cpp
#	Caso haja a necessidade, poderia ser compilado passando os objetos (g++ $< $(OBJ)/*.o -I $(INCLUDE) $(FLAGS) -o $@)
	$(CC) $< $(LIB)/LibUtils.a $(LIB)/LibForm.a -I $(INCLUDE) $(FLAGS) -o $@

# TAG 5	
# Executa o programa (executável em ./CI-App/Bin/)
run:
	$(BIN)/$(CI-APP)

# TAG 6
# Limpa os arquivos objetos, bibliotecas e executáveis para um compilação "full".
clean:
	rm $(OBJ)/*.o
	rm $(LIB)/*.a
	rm $(BIN)/*.exe

