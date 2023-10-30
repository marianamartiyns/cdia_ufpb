/*Sistema de cadastro de produtos

Crie uma classe produto que represente um produto gen�rico.
- campos: valor, codigo_barras, nome_fabricante
Crie uma classe produto_alimenticio que herde da classe produto.
- campos: data_validade, data_fabricacao
Crie uma classe produto_eletronico que herde da classe produto.
- campos: voltagem, potencia
Crie uma classe template estoque que represente uma estoque com multiplos
produtos (alimenticios ou eletronicos).
- A classe deve ter um campo int limite_armazenamento que representa o limite
de produtos no estoque.
- A classe deve ter um campo vector de produtos.
- A classe deve ter um m�todo adicionar_produto() que recebe como par�metro
um produto e o adiciona ao vector de produtos.
- A classe deve ter um m�todo calcular_valor_total() que calcula o valor total
do estoque com base nos produtos adicionados.

Sobrecarregue o operador << para imprimir as informa��es de um objeto da classe estoque.
Sobrecarregue o operador + para adicionar um produto ao estoque.
Sobrecarregue o operador - para remover um produto do estoque.

Crie uma fun��o friend template chamada transferir_produtos() que receba como par�metros
dois objetos da classe estoque (com o mesmo tipo template) e transfira todos os produtos
do primeiro estoque para o segundo estoque.

Adicione tratamento de exce��es ao c�digo para lidar com situa��es em que o usu�rio tente
adicionar produtos acima do limite do estoque (campo limite_armazenamento).

Crie uma funcao main que crie tr�s objetos da classe estoque, com pelo menos tr�s produtos
cada. Imprima as informa��es de cada estoque e transfira os produtos do primeiro estoque
para o segundo estoque. Imprima novamente as informa��es de cada estoque.*/
