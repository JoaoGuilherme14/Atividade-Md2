/*
    Questao 2
    Aluno: João Guilherme Lima Veras Fonseca
    Matricula: 232014039
    Data: 18/10/2025
*/

#include <stdio.h>
int Euclides(int n, int x){
    int mdc, r, Q, aux, y1 = n,y2 = x;
    if(n<x){
        aux = n;
        n = x;
        x = aux;        
    }
    Q = n/x;
    r = n%x;
    printf("mdc(%d,%d) -> %d = %d x %d + %d\n",x,n,n,x,Q,r);
    while(r!=0){
        n = x;
        x = r;
        Q = n/x;
        r = n-(x*Q);
        printf("%d = %d x %d + %d\n",n,x,Q,r);
    }
    mdc = x;
    printf("mdc(%d,%d) = %d\n",y1,y2 ,mdc);
    return mdc;
}

int minimomc(int mdc,int p, int x, int y){
    int mmc = p/mdc;
    printf("o mmc(%d,%d) = %d\n",x,y,mmc);
    return mmc;
}


int main(){
    int  N, flag = 0 , mdc, mmc;
    printf("Digite o numero de chaves N, de forma que 1 ≤ N ≤ 10: ");
    scanf("%d",&N);
    int c[N];
    while(flag!=1){
        if(N==1){
            printf("Como so temos apenas 1 chave, nao e preciso determinar o ano em que as chaves podem ser utilizadas,insira um valor de N maior que 1!!\n");
        }
        else{
            break;
        }
        printf("Digite o numero de chaves N, de forma que 1 ≤ N ≤ 10: ");
        scanf("%d",&N);
    }
    for(int i = 0; i<N;i++){
        printf("\nDigite o ciclo de ativacao da chave C%d, 2 ≤ Ci ≤ 20: ",i+1);
        scanf("%d",&c[i]);
        if(c[i]<2 || c[i]>20){
            printf("Numero de ciclo invalido!!!!!!\n");
            i-=1;
        } 
    }
    printf("Voce escolheu os seguintes numeros de ciclos:\n");
    for(int i = 0;i<N;i++){
        printf("C%d = %d \n",i+1,c[i]);
    }
    printf("Agora para determinar o ano quem que todas as chaves podem ser utilizadas simultaneamente dentro do limite de 50 anos \n");
    printf("vamos calcular o mdc, usando o algoritmo de Euclides e o mmc de todos os ciclos de ativacao, tendo em vista que mmc(x,y) = x*y/mdc(x,y)\n");
    mdc = Euclides(c[0],c[1]);
    mmc = (c[0]*c[1])/mdc;
    printf("o mmc(%d,%d) = %d\n",c[0],c[1],mmc);
    for(int i = 2;i<N;i++){
        int p = mmc*c[i];
        mdc = Euclides(mmc,c[i]);
        mmc = minimomc(mdc,p,mmc,c[i]);

    }
    printf("Calculamos o mmc das chaves, pois e a forma de descobrir o primeiro ano em que todas as chaves podem ser utilizadas simultaneamente\n");
    printf("O mmc(C1,C2,..C%d) = %d\n",N,mmc);
    if(mmc>50){
        printf("Nao existe ano valido, pois todas as chaves nao podem ser utiliadas simultaneamente em menos de 50 anos!!!!\n");
    }
    else{
        
        printf("Todas as chaves podem ser usadas simultaneamente dentro de %d anos\n",mmc);
    }
    return 0;
}