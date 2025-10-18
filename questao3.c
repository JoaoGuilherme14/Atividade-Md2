/*
    Questão 3
    Aluno: João Guilherme Lima Veras Fonseca
    Matrícula: 232014039
    Data: 18/10/2025
*/

#include <stdio.h>
#include <math.h>

int main() {
    int N;
    while (1) {
        printf("Digite um número inteiro N (1 ≤ N ≤ 100000): ");
        scanf("%d", &N);
        if (N >= 1 && N <= 100000) break;
        printf("Número inválido!\n");
    }

    printf("\nFatoração Prima de %d\n", N);
    int n = N;
    int prime[100000];
    int expoente[100000];
    int count = 0;

    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                exp++;
            }
            prime[count] = p;
            expoente[count] = exp;
            printf("Fator primo encontrado: %d^%d\n", p, exp);
            count++;
        }
    }
    if (n > 1) {
        prime[count] = n;
        expoente[count] = 1;
        printf("Fator primo encontrado: %d^1\n", n);
        count++;
    }

    double tau = 1;
    double sigma = 1;
    printf("\n=== Cálculo de τ(N) e σ(N) ===\n");
    for (int i = 0; i < count; i++) {
        int p = prime[i];
        int a = expoente[i];
        tau *= (a + 1);
        double termo = (pow(p, a + 1) - 1) / (p - 1);
        sigma *= termo;
        printf("p=%d, a=%d → termo σ=%lf\n", p, a, termo);
    }

    double razao = sigma / tau;
    printf("\nτ(N) = %.0lf\n", tau);
    printf("σ(N) = %.0lf\n", sigma);
    printf("Razão de Eficiência R(N) = σ(N)/τ(N) = %.2lf\n", razao);

    return 0;
}
