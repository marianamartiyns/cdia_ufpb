/*Sistema de Gerenciamento de Estoque em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de estoque para uma loja de eletrônicos. O programa deve ser orientado a objetos e deve incorporar os seguintes recursos:

1. **Classe `produto`**:

    - Crie uma classe chamada `produto` que represente um produto eletrônico com as seguintes informações:
        - Nome do produto.
	- Descrição do produto (representada como um tipo de dado flexível usando templates).
        - Número de série (único para cada produto).
        - Preço unitário.
        - Quantidade em estoque.

    - Implemente um construtor que inicialize as informações do produto, incluindo a descrição como um tipo flexível
    - Implemente métodos para:
        - Atualizar o preço unitário do produto.
        - Adicionar unidades ao estoque.
        - Vender unidades do produto.

2. **Classe `gerenciador_estoque`**:

    - Crie uma classe de controle chamada `gerenciador_estoque` com métodos e atributos de classe (estáticos) para rastrear informações globais sobre o estoque, incluindo:
        - O número total de produtos no estoque.
        - O valor total do estoque.
        - O produto mais caro em estoque.

    - Utilize o padrão de projeto Singleton para garantir que apenas uma instância da classe `gerenciador_estoque` exista.

    - Implemente métodos estáticos para:
        - Adicionar um produto ao estoque.
        - Listar todos os produtos em estoque.
        - Calcular o valor total do estoque.
        - Encontrar o produto mais caro em estoque.

3. **Classe `cliente`**:

    - Crie uma classe chamada `cliente` que represente um cliente da loja com as seguintes informações:
        - Nome do cliente.
        - ID do cliente.
        - Histórico de compras (utilize um contêiner da STL, como `vector`).

    - Implemente métodos para:
        - Adicionar produtos ao carrinho de compras.
        - Finalizar uma compra, que envolve a transferência dos produtos do carrinho para o histórico de compras do cliente.

4. **Classe `loja`**:

    - Crie uma classe chamada `loja` que represente a loja de eletrônicos.
    - Implemente um método para atender um cliente, permitindo que o cliente adicione produtos ao carrinho e finalize a compra.

Implemente o sistema de gerenciamento de estoque conforme os requisitos acima, incorporando tratamento de exceções para lidar com situações de erro, como preços inválidos, estoque insuficiente e operações inválidas.
*/
