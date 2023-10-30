/* Sistema de pagamentos

Crie uma classe pagamento que represente um pagamento gen�rico.
- campos: valor, data, numero_cartao
Crie uma classe pagamento_online que herde da classe pagamento.
- campos: nome_site, codigo_seguranca
Crie uma classe pagamento_presencial que herde da classe pagamento.
- campos: nome_loja
Crie uma classe template fatura que represente uma fatura com multiplos
pagamentos (online ou presencial).
- A classe deve ter um campo double limite_credito que representa o limite
- A classe deve ter um campo vector de pagamentos.
- A classe deve ter um m�todo adicionar_pagamento() que recebe como par�metro
um pagamento e o adiciona ao vector de pagamentos.
- A classe deve ter um m�todo calcular_valor_total() que calcula o valor total
da fatura com base nos pagamentos adicionados.

Sobrecarregue o operador << para imprimir as informa��es de um objeto da classe fatura.
Sobrecarregue o operador + para adicionar um pagamento a uma fatura.
Sobrecarregue o operador - para remover um pagamento de uma fatura.

Crie uma fun��o friend template chamada transferir_pagamentos() que receba como par�metros
dois objetos da classe fatura (com o mesmo tipo template) e transfira todos os pagamentos
da primeira fatura para a segunda fatura.

Adicione tratamento de exce��es ao c�digo para lidar com situa��es em que o usu�rio tente
adicionar pagamentos acima do limite (campo limite_credito).

Crie uma funcao main que crie tr�s objetos da classe fatura, com pelo menos tr�s pagamentos
cada. Imprima as informa��es de cada fatura e transfira os pagamentos da primeira fatura
para a segunda fatura. Imprima novamente as informa��es de cada fatura.
*/
