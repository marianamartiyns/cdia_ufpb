/*Sistema de Gerenciamento de Funcion�rios em C++

Desenvolva um programa em C++ que simule um sistema de gerenciamento de funcion�rios em uma empresa. O programa deve ser orientado a objetos e suportar diferentes tipos de funcion�rios, como empregados regulares, gerentes e estagi�rios. Al�m disso, o programa deve incorporar os seguintes recursos:

1. **Tratamento de Exce��es**:
   - Implemente tratamento de exce��es para lidar com erros, como valores inv�lidos de sal�rio ou acesso a funcion�rios inexistentes.

2. **M�todos e Atributos de Classe**:
   - Crie m�todos de classe para realizar opera��es comuns em funcion�rios, como aumentar o sal�rio de todos os funcion�rios em uma porcentagem.
   - Implemente atributos de classe, como um contador para manter o n�mero total de funcion�rios na empresa.

3. **Padr�o de Projeto Singleton**:
   - Utilize o padr�o de projeto Singleton para criar uma classe `Empresa` que represente a empresa como uma �nica inst�ncia em todo o programa. Isso garantir� que apenas uma empresa exista.

4. **Templates**:
   - Use templates para criar uma estrutura de dados flex�vel que possa conter funcion�rios de diferentes tipos.

5. **Estruturas de Dados STL**:
   - Utilize as estruturas de dados da STL (Standard Template Library) para armazenar os funcion�rios da empresa, como um `vector` ou `map`.

Requisitos:

1. Crie uma classe base chamada `funcionario` que contenha informa��es comuns a todos os funcion�rios, como nome, ID e sal�rio. Use templates para permitir diferentes tipos num�ricos para o sal�rio (por exemplo, `double` ou `int`).

2. Derive classes para representar diferentes tipos de funcion�rios:
   - `empregado_regular`: Funcion�rio regular com sal�rio fixo.
   - `gerente`: Funcion�rio com um sal�rio fixo e b�nus adicional.
   - `estagiario`: Funcion�rio em treinamento com um sal�rio menor.

3. Use heran�a m�ltipla para criar uma classe `empregado_gerente` que herda de ambas as classes `empregado_regular` e `gerente`. Este funcion�rio � um empregado regular com responsabilidades de gerenciamento e recebe tanto um sal�rio fixo quanto um b�nus.

4. Implemente o tratamento de exce��es para opera��es como tentativas de criar funcion�rios com informa��es inv�lidas.

5. Crie uma classe `empresa` que segue o padr�o Singleton e mant�m um registro de todos os funcion�rios da empresa. Implemente m�todos para adicionar funcion�rios, calcular sal�rios, listar funcion�rios e aumentar o sal�rio de todos os funcion�rios.

*/
