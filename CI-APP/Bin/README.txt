  ____ ___        _                  _   ___  
 / ___|_ _|      / \   _ __  _ __   / | / _ \ 
| |    | |_____ / _ \ | '_ \| '_ \  | || | | |
| |___ | |_____/ ___ \| |_) | |_) | | || |_| |
 \____|___|   /_/   \_\ .__/| .__/  |_(_)___/ 
                      |_|   |_|               


Definição
  CI-App: Programa desenvolvido de acordo com as atribuições solicitadas para o Projeto ATM 2019 [1]. Resumindo,
  o programa simula as operações do formulário de CI [2], que hoje é usado em forma de papel. Com o programa, o
  registro é feito de forma eletrônica (na memória do computador, enquanto o programa está aberto). Desta forma, 
  os dados de quem está enviando ("DE: "), de quem irá receber ("PARA: "), assunto ("ASSUNTO: "), e mensagem 
  ("MESAGEM: ") são todos registrados de forma eletrônica. Obs.: ("DATA: ") e ("ID.: ") são gerados automaticamente
  pelo programa. E, é possível, "Gerar uma impressão em arquivo" (*.txt).

Instalação (Versao S.O. Linux Desktop // Ainda não portado para S.O. Windows)
  *Pre-requisitos:
    -Make: (GNU make), utilitário para modularizar e parametrizar as compilações e link-edições;
    -GCC: Compilador (GNU C/C++), para gerar os executáveis;
    -Git/Github: Versionador de código e Repositório de códigos online.
  
  *Download do Projeto [3]:
    $ git clone https://github.com/aceiro/atm_2019.git
      Ao fazer isso será baixada a pasta do Projeto "atm_2019"

  *Compilação e Instalação:
    $ cd ./atm_2019/CI-APP/
      Acessando o conteúdo da pasta do Projeto.
    
    $ pwd
      Ao fazer isso você devera estar em "../atm_2019/CI-APP/"
    
    $ make all
      Aqui, o Projeto CI-App será compilado de acordo com as regras e parametrizações necessárias.
      Um executável será gerado em "../atm_2019/CI-APP/Bin/CI-App.exe"
    
    $ cd ./Bin/
      Aqui, estará indo para a pasta onde o executável foi gerado.

    $ ./CI-App.exe
      Aqui o programa principal está pronto, e ao fazer isso terá acesso ao Menu como abaixo.
      Programa compilado, instalado e pronto para uso. Basta usar a setas para acima e para abaixo,
      para mover-se nas opções do Menu.

                          CI-App 1.0

          Mova setas (p/ Acima ou p/ Abaixo) para escolher uma opção: 

           -> Atualizar um registro de CI
              Listar/Localizar um registro de CI
              Criar um novo registro de CI
              Apagar um registro de CI
              Imprimir um registro de CI
              Ajuda / Sobre
              Finalizar o Programa

Utilização
  Para cada funcionalidade do progrma, existe uma função no Menu. Logo, todas as funções possíveis
  poderão ser acessadas pelo mesmo.

  *Opções do Menu:
    -Criar um novo registro de CI:
      Essa é operação primária, em relação as demais opções relacionadas 
      ao registro de uma CI. Aqui, você deverá seguir a sequência da entrada de dados. Deverá entrar com 
      dados válidos [4] (recomendamos ler a documentação do projeto, antes do uso). Equanto todos os dados
      não forem preenchidos, o programa não libera a opção de entrada.

    -Listar/Localizar um registro de CI:
      Aqui podemos consultar os dados de um registro de CI específico.
      Como regra, é necessário o ID. de uma CI para consultá-la, e por este motivo, ao acessar esta opção
      (quando existem registros que já foram criados), o programa mostra uma listagem com os campos de ID.,
      DATA e ASSUNTO, para que possa escolher e usar o ID para consulta (CTRL+C, CTRL+V). Caso não entre com
      dados válidos, existente, ou nenhum dado, após pressionar a telca ENTER 5 vezes, o programa volta para
      tela de Menu, cancelando o processo.

    -Atualizar um registro de CI:
      O sistema aqui é mesmo do campo de Listar Dados. Inclusive a questão do
      cancelamento da opção, após 5 tentativas. A diferença, é que após escolher o ID, você também deve repassar
      a letra referente ao campo que deseja alterar: "A" - campo "DE:", "B" - campo "PARA:", 
      "C" - campo "ASSUNTO:" e "D" - campo "MENSAGEM:". Aqui, caso entre com dados em desacordo, após 5 tentativas,
      a operação é cancelada. Em uma operação com sucesso, o referido campo será alterado conforme as regras.

    -Apagar um registro de CI:
      Seguindo a mesma lógica de validação (uso do ID como referência e 5 tentivas), aqui quando você escolher
      um ID válido, e submeter o mesmo, o registro da CI, em questão será excluído da base de 
      dados (estrutura de dados alocada em memória).

    -Imprimir um registro de CI:
      Imprime um registro de CI em um arquivo "txt", na pasta corrente do programa 
      "../atm_2019/CI-APP/Bin/", com o nome ID.txt (Ex.: 20190625162033.txt). Pode ser aberto com um editor de texto
      de sua preferência.

    -Ajuda / Sobre:
      Exibe este texto de ajuda.

    -Finalizar o Programa:
      Finaliza a execução do programa, e limpa os dados em memória (você trabalhar com o programa aberto, master
      ao fechá-los, os dados são perdidos).

Módulo de Testes
  O Módulo de Teste é implementado em um nível de desenvovlimento. Caso queira utilizá-lo, recomendamos consultar
  a Documentação do Projeto para mais informações.

Referências:
  [1] - https://github.com/aceiro/atm_2019
  [2] - https://github.com/aceiro/atm_2019/blob/master/ci.png
  [3] - https://github.com/aceiro/atm_2019.git
  [4] - https://github.com/aceiro/atm_2019/blob/master/ATIVIDADES_MULTIDISCIPLINARES_2_2019.pdf
