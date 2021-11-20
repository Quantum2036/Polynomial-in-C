#include "polynomial.h"

Polynomial PolyProduct(Polynomial po_1, Polynomial po_2)
{//多项式乘法：多项式 x 多项式
    Polynomial po = InitPoly();
    po.n = po_1.n + po_2.n;

    for(int i = 0; i <= po_1.n; i++) {
        for(int j = 0; j <= po_2.n; j++) {
            po.a[i+j] += po_1.a[i] * po_2.a[j];
        }
    }

    return po;
}

Polynomial PolyProduct_i(Polynomial po_1, double num)
{//多项式乘法：多项式 x 实数
    Polynomial po = InitPoly();
    po = po_1;

    for(int i = 0; i <= po.n; i++) {
        po.a[i] *= num;
    }

    return po;
}

Polynomial PolyAddition(Polynomial po_1, Polynomial po_2)
{//多项式加法：多项式 + 多项式
    Polynomial po = InitPoly();
    po.n = po_1.n > po_2.n ? po_1.n : po_2.n;

    for(int i = 0; i <= po.n; i++) {
        po.a[i] = po_1.a[i] + po_2.a[i];
    }

    return po;
}

Polynomial PolyAddition_i(Polynomial po_1, double num)
{//多项式加法：多项式 + 实数
    Polynomial po = InitPoly();
    po = po_1;

    po.a[0] += num;

    return po;
}

Polynomial  PolyPower_i(Polynomial po_1, int num)
{//多项式乘方：多项式 ^ 正整数
    Polynomial po = po_1;

    if(num > 0) {
        for(int i = 1; i < num; i++)
            po = PolyProduct(po, po_1);
    } else if (num == 0) {
        po = InitPoly();
        po.n = 0;
        po.a[0] = 1;
    } else {
        fprintf(stderr, "PolyPower_i arg 'num' must > 0\n");
        exit(-1);
    }

    return po;
}

Polynomial InitPoly(void)
{//初始化一个全零形式的多项式
    Polynomial po;
    po.n = -1;

    for(int i = 0; i < MAX_POLYNOMIAL_RANK; i++)
        po.a[i] = 0.0;

    return po;
}

Polynomial InputPoly(void)
{//用户输入多项式，以非字符结束
    Polynomial po = InitPoly();
    double value = 0.0;
    int n = -1;

    puts("Input a polynomial:");
    while( scanf("%lf", &value) || n == 100 ) {
        n++;
        po.a[n] = value;
    }
    po.n = n;

    int i = 0;
    double temp = 0.0;
    while(po.n - 2*i >= 1) {
        temp = po.a[i];
        po.a[i] = po.a[n-i];
        po.a[n-i] = temp;
        i++;
    }

    return po;
}

double PolyValue(Polynomial po_1, double x)
{//以x代入多项式得到值
    double sum = 0.0;

    for(int i = 0; i <= po_1.n; i++) {
        sum += po_1.a[i] * pow(x,i);
    }

    return sum;
}

void DispPoly(Polynomial po)
{//显示一个多项式
    if(po.n == -1) {
        puts("Empty polynomial.\n");
        return;
    }

    double n, m;
    printf("Polynomial: ");
    puts("\b");

    if(po.a[po.n] < 0) {
        printf("-");
    }

    for(int i = po.n; i > 0; i--) {
        n = po.a[i-1];
        m = fabs(po.a[i]);

        if(m < 1e-15)
            continue;

        printf("%.6fX^%d", m, i);
        if(n < 0) {
            printf(" - ");
        }
        else
            printf(" + ");
    }
    printf("%.6f\n\n", fabs(po.a[0]));
}

Polynomial  Debug_LoadPoly(double* data)
{//将一个doule数组载入为多项式
    Polynomial po = InitPoly();

    for(int i = 0; i <= MAX_POLYNOMIAL_RANK; i++) {
        if(data[i] != 0) {
            po.n = i;
            po.a[i] = data[i];
        }
    }
    return po;
}

void Debug_Poly(Polynomial po)
{//测试用
    printf("debug.po.n = %d\n", po.n);
    printf("debug.po.data =\n");
    for(int i=0; i < MAX_POLYNOMIAL_RANK; i++) {
        printf("%.2f    ", po.a[i]);
        if((i+1) % 10 == 0)
            puts("");
    }
}
