/*Sistema de cadastro de produtos

Crie uma classe produto que represente um produto genérico.
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
- A classe deve ter um método adicionar_produto() que recebe como parâmetro
um produto e o adiciona ao vector de produtos.
- A classe deve ter um método calcular_valor_total() que calcula o valor total
do estoque com base nos produtos adicionados.

Sobrecarregue o operador << para imprimir as informações de um objeto da classe estoque.
Sobrecarregue o operador + para adicionar um produto ao estoque.
Sobrecarregue o operador - para remover um produto do estoque.

Crie uma função friend template chamada transferir_produtos() que receba como parâmetros
dois objetos da classe estoque (com o mesmo tipo template) e transfira todos os produtos
do primeiro estoque para o segundo estoque.

Adicione tratamento de exceções ao código para lidar com situações em que o usuário tente
adicionar produtos acima do limite do estoque (campo limite_armazenamento).

Crie uma funcao main que crie três objetos da classe estoque, com pelo menos três produtos
cada. Imprima as informações de cada estoque e transfira os produtos do primeiro estoque
para o segundo estoque. Imprima novamente as informações de cada estoque.*/
