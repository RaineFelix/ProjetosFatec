//Grupo: Márcio Roberto, Matheus Biazotto, Matheus Manzoli, Raíne Felix
//2º SEMESTRE ADS NOTURNO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para converter graus para radianos
//M_PI é uma constante da biblioteca Math.h, que retorna o valor de PI.
float toRad(float degree){
return degree * M_PI / 180;
}

// Função para converter radianos para graus
float toDeg(float rad){
return rad * 180 / M_PI;
}

void awaitRouter() {
    char character;
    printf("\nDigite qualquer caractere e pressione 'ENTER' para continuar...");
    scanf(" %c", &character);
    system("cls || clear");
    menu();
}

void menu()
{
    int op;
    
    printf("\n+-------------------------------------------------------+");
    printf("\n\tCalculadora de Geometria  - 2022");
    printf("\n+-------------------------------------------------------+");
    printf("\n\tPor Marcio Roberto, Matheus Biazotto,");
    printf("\n\tMatheus Manzoli e Raíne Felix");
    printf("\n+-------------------------------------------------------+");
    printf("\n\t[ Ola! Seja bem-vindo! :) ]");
    printf("\n\n[ 1 ] - Seno");
    printf("\n[ 2 ] - Cosseno");
    printf("\n[ 3 ] - Tangente");
    printf("\n[ 4 ] - Fração");
    printf("\n[ 5 ] - Potência");
    printf("\n[ 6 ] - Sair");
    printf("\n+-------------------------------------------------------+");
    printf("\n> Digite sua opção: ");
    scanf("%d", &op);
    
    if(op == 1){
        system("cls || clear");
        getSen();
    }else if(op == 2){
        system("cls || clear");
        getCos();
    }else if(op == 3){
        system("cls || clear");
        getTan();
    }else if(op == 4){
        system("cls || clear");
        getFra();
    }else if(op == 5){
        system("cls || clear");
        getPow();
    }else if(op == 6){
        system("cls || clear");
        printf("Ate mais!");
    }else{
        system("cls || clear");
        printf("Opcao invalida!");
    }
    if (op != 6) {
        awaitRouter();  
    }
}

void getSen(){
    double angle;

    printf("\n========== SENO ==========\n");
    printf("\nDigite o valor do angulo em RADIANOS: ");
    scanf("%lf", &angle);
    printf("\n%.4lf Radianos = %.4lf Graus", angle, toDeg(angle));
    printf("\nSENO(%.4lf Radianos OU %.4lf Graus) = %.4lf\n", angle, toDeg(angle), sin(angle));
}

void getCos() {
    printf("\n========== COSSENO ==========");
    
    double angle;
    
    printf("\nDigite o angulo em RADIANOS: ");
    scanf("%lf",&angle);
    
    printf("%.4lf Radianos = %.4lf Graus", angle, toDeg(angle));
    
    printf("\nCOS(%.4lf Radianos OU %.4lf Graus) = %.4lf", angle, toDeg(angle), cos(angle));
}

void getFra(){ 
    double x, resultado;
    printf(" ============= f(x) = 1/x =============\n");
    printf("Digite o valor de 'x':");
    scanf("%lf", &x);

    if (x == 0) {
        printf("============================================================\n");
        printf("Nenhum numero pode ser dividido por 0! Digite novamente!\n");
        printf("============================================================\n");
        getFra();
    }
    else {

        resultado = (1 / x);
        printf("O resultado de f(x) 1/%.4f = %.4lf  \n", x, resultado);
    }
    
}

void getPow() {
    double base, expoent;

    printf("\n========== POTENCIACAO ==========\n");
    printf("\n\t y");
    printf("\n\tX");
    printf("\nDigite o valor de X: ");
    scanf("%lf", &base);

    printf("\n\t y");
    printf("\n\t%.4lf", base);
    printf("\nDigite o valor de y: ");
    scanf("%lf", &expoent);

    printf("\n\t (y)%.4lf", expoent);
    printf("\n\t(X)%.4lf = %.4lf\n", base, pow(base, expoent));
}

void getTan()
{
    float x, graus, result;
    
    printf("================= TANGENTE ================");
    
    printf("\n\nDigite o valor de X em RADIANOS: ");
    scanf("%f", &x);
    
    if(x > 0){
        //CONTAS
        graus = toDeg(x);
        result = tan(x);
        
        //EXIBIÇÃO RESULTADOS
        printf("%.4f Radianos = %.4f Graus", x, graus);
        printf("\nTAN(%.4f Radianos OU %.4f Graus) = %.4f", x, graus, result);
        
    }
    else{
        system("cls || clear");
        
        printf("Digite um valor maior que 0!\n");
        menu();
    }
    
}

int main() {
    system ("cls || clear");
    menu();
    return 0;
}
