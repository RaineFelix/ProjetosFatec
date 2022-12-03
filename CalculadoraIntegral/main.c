#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

void ex1(double k, double a, double b) {

    double integral;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("       Funcao k dx \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Digite o valor de k para a construcao da funcao desejada:\n");
    scanf("%lf", &k);
    printf("Digite o valor \"a\" do extremo inferior da integral:\n");
    scanf("%lf", &a);
    printf("Digite o valor \"b\" do extremo superior da integral:\n");
    scanf("%lf", &b);

    integral = (k * b) - (k * a);
    printf("integral = (%.2lf * %.2lf) - (%.2lf * %.2lf)\n", k, b, k, a);
    printf("O valor da integral da funcao de a ate b eh: %.4lf\n", integral);


}
void ex2(double k, double a, double b){
    double integral;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("        Funcao x^k\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Digite o valor de k para a construcao da funcao desejada:\n");
    scanf("%lf", &k);
    printf("Digite o valor \"a\" do extremo inferior da integral:\n");
    scanf("%lf", &a);
    printf("Digite o valor \"b\" do extremo superior da integral:\n");
    scanf("%lf", &b);

    if (k<0 && k!=-1){

        k = k * (-1);
        printf("integral = (-1 / %.2lf * (%.2lf ^ %.2lf)) - (-1 / %.2lf * (%.2lf ^ %.2lf))\n", k-1, b, k-1, k-1, a, k-1);

        integral = (-1 / ((k-1) * pow(b, k-1))) - (-1 / ((k-1) * pow(a, k-1)));

    } else if (k == -1){

        integral = log(b) - log(a);

    }
    else {

        printf("I = ((%2lf ^ %.2lf) / %.2lf) - ((%2lf ^ %.2lf) / %.2lf)\n", b, k+1, k+1, a, k+1, k+1);

        integral = (pow(b,k+1)/(k+1)) - (pow(a,k+1) / (k+1));

    }

    printf("O valor da integral da funcao de a ate b eh: %.4lf\n", integral);

    }


void ex3(double a, double b){
    double integral;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("      Funcao 1/x dx\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Digite o valor \"a\" do extremo inferior da integral:\n");
    scanf("%lf", &a);
    printf("Digite o valor \"b\" do extremo superior da integral:\n");
    scanf("%lf", &b);

    printf("integral = log(%.2lf) - log(%.2lf)\n", b, a);
    integral = log(b) - log(a);

    printf("O valor da integral da funcao de a ate b eh: %.4lf\n", integral);

}


int main() {
    double k, a, b;
    int opcao = 0;
    while (opcao != 4)
    {
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("           MENU\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Digite a integral que deseja calcular:\n");
        printf("|1| k dx\n");
        printf("|2| x^k\n");
        printf("|3| 1/x\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ex1(k, a, b);
                break;
            case 2:
                ex2(k, a, b);
                break;
            case 3:
                ex3(a, b);
            default:
                printf("Favor digitar um numero valido.\n");

        }
        Sleep(4000);
        system("cls");

    }
    return 0;
}
