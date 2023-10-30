/*Sistema de Gerenciamento de Funcionários em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de funcionários em uma empresa. O programa deve ser orientado a objetos e suportar diferentes tipos de funcionários, como empregados regulares, gerentes e estagiários. Além disso, o programa deve incorporar os seguintes recursos:

1. **Tratamento de Exceções**:
   - Implemente tratamento de exceções para lidar com erros, como valores inválidos de salário ou acesso a funcionários inexistentes.

2. **Métodos e Atributos de Classe**:
   - Crie métodos de classe para realizar operações comuns em funcionários, como aumentar o salário de todos os funcionários em uma porcentagem.
   - Implemente atributos de classe, como um contador para manter o número total de funcionários na empresa.

3. **Padrão de Projeto Singleton**:
   - Utilize o padrão de projeto Singleton para criar uma classe `Empresa` que represente a empresa como uma única instância em todo o programa. Isso garantirá que apenas uma empresa exista.

4. **Templates**:
   - Use templates para criar uma estrutura de dados flexível que possa conter funcionários de diferentes tipos.

5. **Estruturas de Dados STL**:
   - Utilize as estruturas de dados da STL (Standard Template Library) para armazenar os funcionários da empresa, como um `vector` ou `map`.

Requisitos:

1. Crie uma classe base chamada `funcionario` que contenha informações comuns a todos os funcionários, como nome, ID e salário. Use templates para permitir diferentes tipos numéricos para o salário (por exemplo, `double` ou `int`).

2. Derive classes para representar diferentes tipos de funcionários:
   - `empregado_regular`: Funcionário regular com salário fixo.
   - `gerente`: Funcionário com um salário fixo e bônus adicional.
   - `estagiario`: Funcionário em treinamento com um salário menor.

3. Use herança múltipla para criar uma classe `empregado_gerente` que herda de ambas as classes `empregado_regular` e `gerente`. Este funcionário é um empregado regular com responsabilidades de gerenciamento e recebe tanto um salário fixo quanto um bônus.

4. Implemente o tratamento de exceções para operações como tentativas de criar funcionários com informações inválidas.

5. Crie uma classe `empresa` que segue o padrão Singleton e mantém um registro de todos os funcionários da empresa. Implemente métodos para adicionar funcionários, calcular salários, listar funcionários e aumentar o salário de todos os funcionários.

*/
