# 1 - Com o código completo e preenchido corretamente, qual seria a saída com os valores: H: 7, G: 3, Zn: 11, x: 10, n1: 13
    Saída: Valor final da congruencia: 4

# Considere o código abaixo, que realiza o cálculo da divisão modular H ÷ G (mod Zn) e depois computa a^x mod n1, aplicando o Pequeno Teorema de Fermat ou o Teorema de Euler, conforme a natureza de n1, classifique como Verdadeiro (V) ou Falso (F) cada uma das afirmativas a seguir:

    (V) O algoritmo de Euclides estendido é utilizado para calcular o inverso modular de um número.
        O código mostrado (inversoModular) é justamente uma implementação do Algoritmo de Euclides Estendido para encontrar o inverso modular.
    (F) Se mdc(G, Zn) ≠ 1, o programa ainda consegue encontrar o inverso de G em Zn.
        O inverso modular só existe se gcd(G, Zn) = 1. Caso contrário, o resultado não é válido.
    (V) A operação (H * inverso) % Zn representa a divisão modular de H por G.
        Na aritmética modular, dividir por G equivale a multiplicar por G⁻¹ mod Zn.
    (F) Se n1 for primo, o código aplica o Pequeno Teorema de Fermat para simplificar o cálculo de a^x mod n1.
        Embora o Pequeno Teorema de Fermat possa ser aplicado nesse contexto, o código em questão não faz isso.
        Ele simplesmente usa o método de exponenciação modular por quadratura (exponenciação rápida), que não depende do teorema.
    (F) A função powMod implementa o cálculo de potência modular utilizando multiplicações diretas sem otimização.
        A função powMod normalmente (e corretamente) usa exponenciação rápida (por quadrados), que é otimizada — não multiplicações diretas.
    (V) Quando o resultado do inverso é negativo, o código ajusta o valor somando o módulo m0.
        O trecho if (x1 < 0) x1 += m0; realiza exatamente essa correção.
    (F) O cálculo de fi(n1) (função totiente de Euler) é utilizado apenas quando n1 não é primo.
        Apesar de ser uma afirmação teórica correta em outros contextos, o código fornecido não mostra uso de φ(n1) em nenhum ponto.
        Portanto, dentro do escopo do código analisado, essa afirmação é falsa.
