# the awkward squad

features legais de programação funcional, segundo o texto:
- funcoes de alta ordem
- tipos de dados algebraicos
- polimorfia de tipos..... etc

4 coisas porém são cruciais e essenciais para programas úteis:
- input output
- tratamento de erros
- concorrencia
- interface com componentes de outras linguagens



- call by value vs laziness
incompatibilidade entre efeitos colaterais e avaliação preguiçosa:
muitos efeitos colaterais precisam acontecer em um determinado momento do programa. com uma avaliação preguiçosa, isso é altamente dificil de garantir, visto que a ordem da avaliação dos parametros de uma funcao não é garantida. 
strict vs non strict languages?
o que é strict evaluation?
formas de avaliar funções onde todos os seus parâmetros precisam ser avaliados antes da aplicação da função.

o que é non-strict evaluation?
uma forma de avaliação de funções onde ela pode retornar um resultado antes da avaliação dos seus parâmetros, como por exemplo na avaliação preguiçosa.

linguagens preguicosas precisam ser puramente funcionais?

## Um servidor em haskell

Como exemplo de programa que lida com todos os problemas citados, o paper fala sobre um servidor em haskell:

  - é intensivo em I/o
  - requer concorrencia
  - requer uso de bibliotecas baixo nivel de I/O
  - requer robustez no tratamento de erros, timing outs, etc... é de fato uma programação com efeitos colaterais




 


 
