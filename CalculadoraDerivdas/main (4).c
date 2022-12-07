//Grupo: Matheus Biazotto, Matheus Manzoli, Raíne Felix
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void line()
{
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
}

void outputMenuItems(char **words, int size)
{
    line();
    printf("\n*** MENU ***\n");
    for (int i = 0; i < size; i++)
    {
        printf("\n[%i] - [%s]", i + 1, words[i]);
    }
    printf("\nDigite sua resposta: >");
}

float toRad(float degree)
{
    return degree * M_PI / 180;
}

void renderPreview_x_k(float k, float x)
{

    if (!k)
    {
        printf("\nf(x) = [ X ^ k ] = K * X ^ k - 1 ");
        return;
    }

    if (!x)
    {
        printf("\nf(x) = [ X ^ %.4f ] = %.4f * X ^ %.4f - 1 ", k, k, k);
        return;
    }

    printf("\n f(x) = [ %.4f ^ %.4f ] = %.4f * %.4f ^ %.4f", x, k, x, k, k - 1);
}

void x_k()
{
    float k = 0, x = 0, result = 0;
    line();
    renderPreview_x_k(k, x);
    printf("\nDigite um valor para K: ");
    scanf("%f", &k);
    renderPreview_x_k(k, x);
    printf("\nDigite um valor para X: ");
    scanf("%f", &x);
    renderPreview_x_k(k, x);
    line();
    printf("\n f(x) =  %.4f * %.4f ^ %.4f = ?", x, k, k - 1);

    result = pow(k * x, k - 1);

    printf("\n f(x) =  %.4f * %.4f ^ %.4f = %.4f", x, k, k - 1, result);
}

int logk()
{
    float k = 0, x = 0, result = 0;
    line();
    printf("\nf(x) = log_K(X) = 1 / (X * ln(K))");
    printf("\n\nDigite um valor para K: ");
    scanf("%f", &k);
    printf("f(x) = log%.4f(X) = 1 / (X * ln(%.4f))", k, k);

    printf("\n\nDigite um valor para X: ");
    scanf("%f", &x);
    printf("\nf(x) = log_%.4f(%.4f) = 1 / (%.4f * ln(%.4f))", k, x, x, k);
    line();

    if (x > 0 && k > 0)
    {
        result = 1 / (x * (log(k)));
        printf("\n\nf(x) = log_%.4f(%.4f) = 1 / (%.4f * ln(%.4f)) ~= %.4f", k, x, x, k, result);
    }
    else
    {
        line();
        printf("\n\nTanto X quanto K devem ser maior que 0!\n");
    }
}

void renderPreview_k_x(float k, float x)
{

    if (!k)
    {
        printf("\nf(x) = [ K ^ x ] = K ^ x * ln(k) ");
        return;
    }

    if (!x)
    {
        printf("\nf(x) = [ %.4f ^ x ] = %.4f ^ x * ln(%.4f) ", k, k, k);
        return;
    }

    printf("\nf(x) = [ %.4f ^ %.4f ] = %.4f ^ %.4f * ln(%.4f) ", k, x, k, x, k);
}

void k_x()
{
    float k = 0, x = 0, result = 0;
    line();
    renderPreview_k_x(k, x);
    printf("\nDigite um valor para K: ");
    scanf("%f", &k);
    renderPreview_k_x(k, x);
    printf("\nDigite um valor para X: ");
    scanf("%f", &x);
    renderPreview_k_x(k, x);
    line();
    printf("\nf(x) = %.4f ^ %.4f * ln(%.4f) = ? ", k, x, k);

    result = pow(k, x) * log(k);

    printf("\nf(x) = %.4f ^ %.4f * ln(%.4f) = %.4f ", k, x, k, result);
}

int tg_x()
{
    float x = 0, result = 0, radianos = 0;
    printf("\nf(x) = tg(x) = sec²(x)");
    line();
    printf("\nDigite o valor de X (em graus): ");
    scanf("%f", &x);
    if (x == 0)
    {
        line();
        printf("\n\nO valor de X nao pode ser 0!\n");
        line();
        tg_x();
    }
    else
    {
        radianos = toRad(x);
        printf("\nf(x) = tg(%.4f) = sec²(%.4f)", radianos, radianos);
        line();

        result = pow(1 / cos(radianos), 2);

        printf("\nf(x) = tg(%.4f) = sec²(%.4f) = %.4f radianos", radianos, radianos, result);
    }
}

void menu()
{
    char *menuItems[] = {
        "f(x) = x^k",
        "f(x) = log_k (x)",
        "f(x) = k^x",
        "f(x) = tg(x)",
        "SAIR",
    };

    int choice;

    while (choice != 5)
    {
        choice = 0;
        outputMenuItems(menuItems, 5);
        scanf("%i", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            x_k();
            break;
        case 2:
            logk();
            break;
        case 3:
            k_x();
            break;
        case 4:
            tg_x();
            break;
        case 5:
            printf("\nAté mais!");
            return 0;
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
    }
}

int main()
{

    menu();

    return 0;
}