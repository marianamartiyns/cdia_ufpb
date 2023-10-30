/* Sistema de pagamentos

Crie uma classe pagamento que represente um pagamento genérico.
- campos: valor, data, numero_cartao
Crie uma classe pagamento_online que herde da classe pagamento.
- campos: nome_site, codigo_seguranca
Crie uma classe pagamento_presencial que herde da classe pagamento.
- campos: nome_loja
Crie uma classe template fatura que represente uma fatura com multiplos
pagamentos (online ou presencial).
- A classe deve ter um campo double limite_credito que representa o limite
- A classe deve ter um campo vector de pagamentos.
- A classe deve ter um método adicionar_pagamento() que recebe como parâmetro
um pagamento e o adiciona ao vector de pagamentos.
- A classe deve ter um método calcular_valor_total() que calcula o valor total
da fatura com base nos pagamentos adicionados.

Sobrecarregue o operador << para imprimir as informações de um objeto da classe fatura.
Sobrecarregue o operador + para adicionar um pagamento a uma fatura.
Sobrecarregue o operador - para remover um pagamento de uma fatura.

Crie uma função friend template chamada transferir_pagamentos() que receba como parâmetros
dois objetos da classe fatura (com o mesmo tipo template) e transfira todos os pagamentos
da primeira fatura para a segunda fatura.

Adicione tratamento de exceções ao código para lidar com situações em que o usuário tente
adicionar pagamentos acima do limite (campo limite_credito).

Crie uma funcao main que crie três objetos da classe fatura, com pelo menos três pagamentos
cada. Imprima as informações de cada fatura e transfira os pagamentos da primeira fatura
para a segunda fatura. Imprima novamente as informações de cada fatura.
*/
