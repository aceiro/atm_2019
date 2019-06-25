```
  ____ ___        _                  _   ___  
 / ___|_ _|      / \   _ __  _ __   / | / _ \ 
| |    | |_____ / _ \ | '_ \| '_ \  | || | | |
| |___ | |_____/ ___ \| |_) | |_) | | || |_| |
 \____|___|   /_/   \_\ .__/| .__/  |_(_)___/ 
                      |_|   |_|               

```

------

***Definição:*** CI-App é um programa desenvolvido de acordo com as atribuições solicitadas para o Projeto ATM 2019 [1]. Resumindo, o programa simula as operações do formulário de CI [2], que hoje é usado em forma de papel. Com o programa, o registro é feito de forma eletrônica (na memória do computador, enquanto o programa está aberto). Desta forma, os dados de quem está enviando *("DE: ")*, de quem irá receber *("PARA: ")*, assunto *("ASSUNTO: ")*, e mensagem  *("MESAGEM: ")* são todos registrados de forma eletrônica. Obs.: *("DATA: ")* e *("ID.: ")* são gerados automaticamente pelo programa. E, é possível, *"Gerar uma impressão em arquivo" (*.txt)*.

***Instalação (Versao S.O. Linux Desktop, ainda não portado para S.O. Windows)***

- ***Pré-requisitos:***

  - ***Make:*** *(GNU make)*, utilitário para modularizar e parametrizar as compilações e link-edições;
  - ***GCC:*** Compilador *(GNU C/C++)*, para gerar os executáveis;
  - ***Git/Github:*** Versionador de código e Repositório de códigos online.

- ***Download do Projeto [3]:***

  - `$ git clone https://github.com/aceiro/atm_2019.git`
    - Ao fazer isso será baixada a pasta do Projeto *"atm_2019"*

- ***Compilação e Instalação:***

  - `$ cd ./atm_2019/CI-APP/`
    - Acessando o conteúdo da pasta do Projeto.
  - `$ pwd`
    - Ao fazer isso você devera estar em *"../atm_2019/CI-APP/"*
  - `$ make all`
    - Aqui, o Projeto CI-App será compilado de acordo com as regras e parametrizações necessárias.  Um executável será gerado em *"../atm_2019/CI-APP/Bin/CI-App.exe"*
  - `$ cd ./Bin/`
    - Aqui, estará indo para a pasta onde o executável foi gerado.
  - `$ ./CI-App.exe`
    - Aqui o programa principal está pronto, e ao fazer isso terá acesso ao Menu como abaixo. Programa compilado, instalado e pronto para uso. Basta usar a setas para acima e para abaixo, para mover-se nas opções do Menu.

  ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_3_IMG_Menu.png)

***Utilização:*** Para cada funcionalidade do progrma, existe uma função no Menu. Logo, todas as funções possíveis poderão ser acessadas pelo mesmo.

- ***Opções do Menu:***

  - ***Criar um novo registro de CI:*** Essa é operação primária, em relação as demais opções relacionadas ao registro de uma CI. Aqui, você deverá seguir a sequência da entrada de dados. Deverá entrar com dados válidos [4] *(recomendamos ler a documentação do projeto, antes do uso)*. Equanto todos os dados não forem preenchidos, o programa não libera a opção de entrada.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_4_IMG_Cadastro.png)

  - ***Listar/Localizar um registro de CI:*** Aqui podemos consultar os dados de um registro de CI específico. Como regra, é necessário o ID. de uma CI para consultá-la, e por este motivo, ao acessar esta opção *(quando existem registros que já foram criados)*, o programa mostra uma listagem com os campos de ID., DATA e ASSUNTO, para que possa escolher e usar o ID para consulta *(CTRL+C, CTRL+V)*. Caso não entre com dados válidos, existente, ou nenhum dado, após pressionar a telca *ENTER 5 vezes*, o programa volta para tela de Menu, cancelando o processo.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_5_IMG_Consultando.png)

  - ***Atualizar um registro de CI:*** O sistema aqui é mesmo do campo de Listar Dados. Inclusive a questão do cancelamento da opção, após 5 tentativas. A diferença, é que após escolher o ID, você também deve repassar a letra referente ao campo que deseja alterar: *"A"* - campo *"DE:"*, *"B"* - campo *"PARA:"*,  *"C"* - campo *"ASSUNTO:"* e *"D"* - campo *"MENSAGEM:"*. Aqui, caso entre com dados em desacordo, após 5 tentativas, a operação é cancelada. Em uma operação com sucesso, o referido campo será alterado conforme as regras.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_6_IMG_Alterando.png)

  - ***Apagar um registro de CI:*** Seguindo a mesma lógica de validação *(uso do ID como referência e 5 tentivas)*, aqui quando você escolher um ID válido, e submeter o mesmo, o registro da CI, em questão será excluído da base de dados *(estrutura de dados alocada em memória)*.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_7_IMG_Excluindo.png)

  - ***Imprimir um registro de CI:*** Imprime um registro de CI em um arquivo *"txt"*, na pasta corrente do programa *"../atm_2019/CI-APP/Bin/"*, com o nome ID.txt *(Ex.: 20190625162033.txt)*. Pode ser aberto com um editor de texto de sua preferência.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_8_IMG_Imprimindo.png)

  - ***Ajuda / Sobre:*** Exibe este texto de ajuda.

    ![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_9_IMG_Ajuda.png)

  - ***Finalizar o Programa:*** Finaliza a execução do programa, e limpa os dados em memória *(você poderá trabalhar com o programa aberto, mas ao fechá-los, os dados são perdidos)*.

***Módulo de Testes (QA):*** O Módulo de Teste é implementado em um nível de desenvovlimento. Caso queira utilizá-lo, recomendamos consultar a Documentação do Projeto para mais informações. Porém, via de regra, no módulo de testes, implementamos a função *"assert" [5]*, nos módulos do CRUD *(Create, Read/Select, Update, Delete)*.

![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_10_IMG_Testes.png)

****

***Estrutura de Diretórios e/ou  Arquivos do Projeto CI-App:***


```
atm_2019
├── ATIVIDADES_MULTIDISCIPLINARES_2_2019.pdf
├── CI-APP
│   ├── App
│   │   ├── CI-App.cpp
│   │   └── empty.log
│   ├── Bin
│   │   ├── CI-App.exe
│   │   ├── empty.log
│   │   └── README.txt
│   ├── Doc
│   │   ├── Activ-1
│   │   │   └── Activity-1.doc
│   │   ├── Activ-2
│   │   │   └── Activity-2.doc
│   │   ├── Activ-3
│   │   │   └── Activity-3.doc
│   │   ├── Activ-4
│   │   │   └── Activity-4.doc
│   │   ├── Examples
│   │   │   ├── CIApp.cpp
│   │   │   ├── Formulario.cpp
│   │   │   └── Main.cpp
│   │   └── Images
│   │       ├── CI-App_1_IMG_Compilacao.gif
│   │       └── CI-App_2_IMG_Execucao.gif
│   ├── Include
│   │   ├── Components.hpp
│   │   ├── empty.log
│   │   ├── ExternLib
│   │   │   └── MenuTemplate
│   │   │       ├── Entry.cpp
│   │   │       ├── ExternFunctions
│   │   │       │   ├── getChar.cpp
│   │   │       │   └── getChar.hpp
│   │   │       ├── MenuTemplate.cpp
│   │   │       └── MenuTemplate.hpp
│   │   ├── Form.hpp
│   │   ├── Help.hpp
│   │   └── PrintingModule.hpp
│   ├── Lib
│   │   ├── empty.log
│   │   ├── LibExtern.a
│   │   ├── LibForm.a
│   │   └── LibUtils.a
│   ├── Makefile
│   ├── Obj
│   │   ├── Components.o
│   │   ├── empty.log
│   │   ├── Entry.o
│   │   ├── FormCreate.o
│   │   ├── FormData.o
│   │   ├── FormDelete.o
│   │   ├── FormSelect.o
│   │   ├── FormToPrint.o
│   │   ├── FormUpdate.o
│   │   ├── getChar.o
│   │   ├── Help.o
│   │   ├── MenuTemplate.o
│   │   └── PrintingModule.o
│   ├── QA
│   │   ├── Bin
│   │   │   ├── empty.log
│   │   │   └── QATest.exe
│   │   ├── Lib
│   │   │   ├── empty.log
│   │   │   └── LibTest.a
│   │   ├── Makefile
│   │   ├── Module
│   │   │   ├── empty.log
│   │   │   ├── QAModule.cpp
│   │   │   └── QAModule.hpp
│   │   ├── Obj
│   │   │   ├── Components.o
│   │   │   ├── empty.log
│   │   │   ├── FormCreate.o
│   │   │   ├── FormData.o
│   │   │   ├── FormDelete.o
│   │   │   ├── FormSelect.o
│   │   │   ├── FormToPrint.o
│   │   │   ├── FormUpdate.o
│   │   │   ├── Help.o
│   │   │   ├── PrintingModule.o
│   │   │   └── QAModule.o
│   │   └── Test
│   │       ├── empty.log
│   │       └── QATest.cpp
│   ├── README.md
│   ├── Src
│   │   ├── Components.cpp
│   │   ├── empty.log
│   │   ├── FormCreate.cpp
│   │   ├── FormData.cpp
│   │   ├── FormDelete.cpp
│   │   ├── FormSelect.cpp
│   │   ├── FormToPrint.cpp
│   │   ├── FormUpdate.cpp
│   │   ├── Help.cpp
│   │   └── PrintingModule.cpp
│   └── teste
├── ci.png
└── README.md

23 directories, 78 files

```

****

**Animações:***

![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_1_IMG_Compilacao.gif)

![](/home/gismar/Workspace/C_C++/Forks/atm_2019/CI-APP/Doc/Images/CI-App_2_IMG_Execucao.gif)

------

***Referências:***

[1] - https://github.com/aceiro/atm_2019
[2] - https://github.com/aceiro/atm_2019/blob/master/ci.png
[3] - https://github.com/aceiro/atm_2019.git
[4] - https://github.com/aceiro/atm_2019/blob/master/ATIVIDADES_MULTIDISCIPLINARES_2_2019.pdf
[5] - http://www.cplusplus.com/reference/cassert/assert/