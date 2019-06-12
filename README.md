# posixlab
Repositorio para o posixlab
Juan Jorge Garcia

gcc example.c -o example;

Feito:
  Conceito I:
  - [ ] Não entregou ou entregou o exemplo disponibilizado sem modificações
  Conceito D:
  - [ ] Implementou algum item, mas não todos, do conceito C. Os arquivos de testes entregues não contém testes para todos os casos descritos.
  Conceito C:
  - [x] Cada teste roda em um processo separado;
  - [x] Processos filhos rodam os testes em paralelo.
  - [x] Processo pai obtem o resultado do processo filho usando .
  Conceito B:
  - [x] Saída dos testes é redirecionada e é impressa por inteiro ao final do teste.
  - [x] É criado um tempo de limite de execução para cada teste usando a chamada .
  - [x] O processo pai avisa quando o processo filho for terminado com erro usando uma mensagem explicativa
  com o nome do erro.
  Conceitos B+, A, A+:
  A partir do conceito B cada uma das seguintes características adiciona um ponto na nota:
  - [x] Processo original responde a Ctrl+C com uma mensagem de confirmação de saída
  - [ ] A biblioteca possui uma API para que cada teste possa modificar seu tempo limite. Ela só pode ser
  chamada uma vez por função e deverá retornar um erro caso seja chamada mais de uma vez.
  - [x] O relatório de erros imprime as funções na ordem de declaração, não na ordem que foram finalizadas, e
  mostra o tempo que cada teste demorou para rodar.
  A partir do conceito C cada uma das seguintes funcionalidades adiciona 0.25 na nota final:
  - [x] os status dos testes são impressos em cores.
  - [ ] ao passar “-html” como argumento seu programa retorna um relatório em HTML bem formatado
  - [x] (adicional ao de cima) se a saída de errros do main for redirecionada para um arquivo imprima tudo sem cores.
