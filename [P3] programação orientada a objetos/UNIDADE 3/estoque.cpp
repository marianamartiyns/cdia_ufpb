/*Sistema de Gerenciamento de Estoque em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de estoque para uma loja de eletr�nicos. O programa deve ser orientado a objetos e deve incorporar os seguintes recursos:

1. **Classe `produto`**:

    - Crie uma classe chamada `produto` que represente um produto eletr�nico com as seguintes informa��es:
        - Nome do produto.
	- Descri��o do produto (representada como um tipo de dado flex�vel usando templates).
        - N�mero de s�rie (�nico para cada produto).
        - Pre�o unit�rio.
        - Quantidade em estoque.

    - Implemente um construtor que inicialize as informa��es do produto, incluindo a descri��o como um tipo flex�vel
    - Implemente m�todos para:
        - Atualizar o pre�o unit�rio do produto.
        - Adicionar unidades ao estoque.
        - Vender unidades do produto.

2. **Classe `gerenciador_estoque`**:

    - Crie uma classe de controle chamada `gerenciador_estoque` com m�todos e atributos de classe (est�ticos) para rastrear informa��es globais sobre o estoque, incluindo:
        - O n�mero total de produtos no estoque.
        - O valor total do estoque.
        - O produto mais caro em estoque.

    - Utilize o padr�o de projeto Singleton para garantir que apenas uma inst�ncia da classe `gerenciador_estoque` exista.

    - Implemente m�todos est�ticos para:
        - Adicionar um produto ao estoque.
        - Listar todos os produtos em estoque.
        - Calcular o valor total do estoque.
        - Encontrar o produto mais caro em estoque.

3. **Classe `cliente`**:

    - Crie uma classe chamada `cliente` que represente um cliente da loja com as seguintes informa��es:
        - Nome do cliente.
        - ID do cliente.
        - Hist�rico de compras (utilize um cont�iner da STL, como `vector`).

    - Implemente m�todos para:
        - Adicionar produtos ao carrinho de compras.
        - Finalizar uma compra, que envolve a transfer�ncia dos produtos do carrinho para o hist�rico de compras do cliente.

4. **Classe `loja`**:

    - Crie uma classe chamada `loja` que represente a loja de eletr�nicos.
    - Implemente um m�todo para atender um cliente, permitindo que o cliente adicione produtos ao carrinho e finalize a compra.

Implemente o sistema de gerenciamento de estoque conforme os requisitos acima, incorporando tratamento de exce��es para lidar com situa��es de erro, como pre�os inv�lidos, estoque insuficiente e opera��es inv�lidas.
*/
