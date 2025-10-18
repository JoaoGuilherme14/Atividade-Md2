/*
    Questao 1
    Aluno: João Guilherme Lima Veras Fonseca
    Matricula: 232014039
    Data: 18/10/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;

int mdc(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int inversoModular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    while (m != 0) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

ll powMod(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    ll b = base % mod;
    while (exp > 0) {
        if (exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return res;
}

int pollardRho(int N) {
    printf("\n--- Fatoração de %d pelo método p de Pollard ---\n", N);
    int x = 2, y = 2, d = 1, i = 1;

    while (d == 1) {
        x = (x * x + 1) % N; 
        y = (y * y + 1) % N;
        y = (y * y + 1) % N; 
        d = mdc(abs(x - y), N);
        printf("Iteração %2d: x=%d, y=%d, mdc(|x-y|, N)=%d\n", i++, x, y, d);

        if (d == N) {
            printf("Falha: ciclo completo sem fator não trivial.\n");
            return -1;
        }
    }

    printf("Fator não trivial encontrado: %d\n", d);
    return d;
}



int chooseE(int phi, int n) {
    for (int e = 2; e < n; ++e)
        if (mdc(e, phi) == 1)
            return e;
    return -1;
}


int charToCode(char ch) {
    if (ch == ' ') return 0;
    ch = toupper((unsigned char)ch);
    if (ch >= 'A' && ch <= 'Z') return 10 + (ch - 'A') + 1;
    return -1;
}

char codeToChar(int code) {
    if (code == 0) return ' ';
    if (code >= 11 && code <= 36) return (char)('A' + (code - 11));
    return '?';
}



ll powModVerbose(ll base, ll exp, ll mod) {
    printf("  Exponenciação modular: %lld^%lld mod %lld\n", base, exp, mod);
    ll res = 1 % mod;
    ll b = base % mod;
    ll e = exp;
    int passo = 1;
    while (e > 0) {
        if (e & 1)
            printf("   Passo %d: bit=1 -> res=(%lld*%lld) mod %lld = %lld\n",
                   passo, res, b, mod, (res * b) % mod);
        else
            printf("   Passo %d: bit=0 -> res=%lld\n", passo, res);
        if (e & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
        passo++;
    }
    printf("  Resultado final: %lld\n", res);
    return res;
}


int main() {
    int N1, N2;
    printf("=== ETAPA 1: Fatoração Interativa (Método ρ de Pollard) ===\n");
    printf("Informe dois números compostos distintos entre 100 e 9999:\n");
    printf("N1: "); scanf("%d", &N1);
    printf("N2: "); scanf("%d", &N2);

    if (N1 < 100 || N2 < 100 || N1 > 9999 || N2 > 9999 || N1 == N2) {
        printf("Erro: valores inválidos.\n");
        return 1;
    }

    printf("Cada Ni deve ser produto de primos distintos.\n");

    int p = pollardRho(N1);
    int q = pollardRho(N2);

    if (p == -1 || q == -1) {
        printf("Falha na fatoração. Encerrando.\n");
        return 1;
    }

    printf("\n=== Resultados da Etapa 1 ===\n");
    printf("p (de N1) = %d\n", p);
    printf("q (de N2) = %d\n", q);

    printf("\n=== ETAPA 2: Geração das Chaves RSA ===\n");

    ll n = (ll)p * q;
    int phi = (p - 1) * (q - 1);
    int E = chooseE(phi, (int)n);
    int D = inversoModular(E, phi);

    printf("n = p*q = %d*%d = %lld\n", p, q, n);
    printf("phi(n) = (p-1)*(q-1) = %d\n", phi);
    printf("E = %d (menor coprimo de phi)\n", E);
    printf("D = inverso de E mod phi = %d\n", D);
    printf("Chave pública:  (n, e) = (%lld, %d)\n", n, E);
    printf("Chave privada: (n, d) = (%lld, %d)\n", n, D);

    getchar();
    char msg[256];
    printf("\n=== ETAPA 3: Criptografia ===\n");
    printf("Digite a mensagem (somente letras e espaços): ");
    fgets(msg, sizeof(msg), stdin);
    if (msg[strlen(msg) - 1] == '\n') msg[strlen(msg) - 1] = '\0';

    int codes[256];
    int len = 0;
    for (int i = 0; i < strlen(msg); i++) {
        int c = charToCode(msg[i]);
        if (c == -1) {
            printf("Caractere inválido: %c\n", msg[i]);
            return 1;
        }
        codes[len++] = c;
    }

    printf("\nPré-codificação:\n");
    for (int i = 0; i < len; i++)
        printf(" '%c' -> %02d\n", msg[i], codes[i]);

    ll cifrado[256];
    printf("\nCriptografando:\n");
    for (int i = 0; i < len; i++) {
        printf("\nBloco %d: M = %02d\n", i + 1, codes[i]);
        if (isPrime((int)n))
            printf("Aplicando Pequeno Teorema de Fermat.\n");
        else if (mdc(codes[i], (int)n) == 1)
            printf("Aplicando Teorema de Euler.\n");
        else
            printf("Usando Teorema da Divisão Euclidiana (sem redução).\n");

        cifrado[i] = powModVerbose(codes[i], E, n);
        printf("  Resultado cifrado C = %lld\n", cifrado[i]);
    }

    printf("\nMensagem cifrada: ");
    for (int i = 0; i < len; i++) printf("%lld ", cifrado[i]);
    printf("\n");

    printf("\n Descriptografando \n");
    int decod[256];
    for (int i = 0; i < len; i++) {
        printf("\nBloco %d: C = %lld\n", i + 1, cifrado[i]);
        decod[i] = powModVerbose(cifrado[i], D, n);
        printf("  Resultado decifrado M = %02d\n", decod[i]);
    }

    printf("\nMensagem decifrada: ");
    for (int i = 0; i < len; i++)
        printf("%c", codeToChar(decod[i]));
    printf("\n");

    return 0;
}
