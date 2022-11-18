h = [] 
s = []

maior = menor = x = y = tot_f = tot_m = soma_m = soma_f = med_f = med_m = 0

print("\n== Dados obtidos a partir da Altura e Sexo de 10 pessoas ==")
print("\nInforme a altura e sexo abaixo.")

for i in range(10):

    h.append(float(input(f"\nAltura da {i+1}ª pessoa (ex: 1.91): ")))
    s.append(input(f"Sexo da {i+1}ª pessoa('F' ou 'M'): ").upper())
        
    if i == 0:
        maior = menor = h[i]
    
    if h[i] >= maior:
        maior = h[i]
        x = s[i]

    elif h[i] <= menor:
        menor = h[i]
        y = s[i]
    
    if 'M' in s[i]:
        tot_m += 1
        soma_m += h[i]
        
    if 'F' in s[i]:
        tot_f += 1
        soma_f += h[i]
        
med_f = soma_f/tot_f
med_m = soma_m/tot_m

print(f"\nAs alturas inseridas foram: {h}")
print(f"Os sexos inseridos foram: {s}")
     
print(f"\nEntre os dados obtidos, temos {tot_m} Homens e {tot_f} Mulheres.")
    
print(f"\nA pessoa mais alta é do sexo {x} com {maior:.2f} metros de altura. Já a mais baixa é do sexo {y} com {menor} de altura.")

print(f"\nA média de altura dos homens foi de: {med_m:.2f} e a das Mulheres ficou: {med_f:.2f}.")