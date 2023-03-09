#import <stdio.h>
#import <locale.h>

int main() {

    setlocale(LC_ALL, " ");

    float fah, celsius;

    printf("\n== Fahrenheit to Celsius ==\n");
    printf("\nFahrenheit: ");
    scanf("%f", &fah);

    celsius = (fah - 32) * 5/9;

    printf("\n%1.f Fahrenheit = %1.f Celsius\n", fah, celsius);

return 0;
}
