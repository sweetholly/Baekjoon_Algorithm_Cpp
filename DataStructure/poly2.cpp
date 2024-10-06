#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101


//각 항에 대한 구조체
typedef struct{
    float coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int size = 6;

// 두개의 정수 비교
int compare(int a, int b){
    if(a > b) return 1;
    else if(a == b) return 0;
    else return -1;
}


//새로운 항을 다항식에 추가
void attach(double coef, int expon){
  if(size > MAX_TERMS){
      printf("항의 개수가 너무 많습니다");
      exit(1);
  }  
  terms[size].coef = coef;
  terms[size].expon = expon;
  size ++;
}


//C = A+B
void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce){
    *Cs = size; //시작 위치
    while(As <= Ae && Cs <= Ce){
        switch (compare(terms[As].expon, terms[Bs].expon)){
            case 1:     //As가 더 큰 경우
                attach(terms[As].coef, terms[As].expon);
                As++;
                break;
            case 0:
                if(terms[As].coef + terms[Bs].coef > 0)
                    attach(terms[As].coef + terms[Bs].coef, terms[As].expon);
                As++; Bs++;
                break;
            case -1:
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
    }
    for(int i = As; i <= Ae; i++){
        attach(terms[i].coef, terms[i].expon);
    }
    for(int i = Bs; i <= Be; i++){
        attach(terms[i].coef, terms[i].expon);
    }
    *Ce = size --;
}


//
void print_poly(int s, int e){
    for(int i = s; i < e; i++){
        printf("%3.1fx^%d", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main()
{
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    print_poly(Cs, Ce);
    return 0;
}
