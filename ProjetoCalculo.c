#include <stdio.h>
#include <stdlib.h>

void AcharSP(int, int, int *, int *);

#define PulaLinha1 printf("\n")
#define PulaLinha2 printf("\n\n")

int main(){
    int N;
    printf("Qual e o grau da Equacao: ");
    scanf("%d", &N);
    if(N<=0){
        return 1;
    }
//-------------------------VARIAVEIS-------------------------------------

    int Eq[N],Eq2[N-1],Eq3[N-2];
    int i;
    int S,P;
    int x1,x2;
    float MLx, MLy;

//------------------------FIM VARIAVEIS---------------------------------

    for(i=N;i>=0;i--){

        printf("Informe o valor de X(%d): ",i);
        scanf("%d", &Eq[i]);
        if(i==N && Eq[i]==0){
            return 1;
        }
    }
    PulaLinha2;
    printf("Equacao: ");   
    for(i=N;i>=0;i--){
        if(Eq[i]!=0 && i!=0){
            printf("%dX(%d)",Eq[i],i);
        }
        if(i>=1 && Eq[i]!=0){
            printf(" + ");
        }
        if (Eq[i]!=0 && i==0){
            printf("%d",Eq[i]);
        }
    }
    PulaLinha2;
        for(i=N;i>0;i--){
            if(Eq[i]!=0){
                Eq2[i-1] = Eq[i]*i;
            }
            else{
                Eq2[i-1] = 0;
            }
        }
        printf("1 Derivada: ");
            for(i=(N-1);i>=0;i--){
            if(Eq2[i]!=0 && i!=0){
                printf("%dX(%d)",Eq2[i],i);
            }
            if(i>=1 && Eq2[i]!=0){
                printf(" + ");
            }
            if (Eq2[i]!=0 && i==0){
                printf("%d",Eq2[i]);
            }
        }


    if(N>2){
            printf("\n2 Derivada: ");
                for(i=N-1;i>0;i--){
                    if(Eq2[i] != 0){
                        Eq3[i-1] = (Eq2[i]*i);
                    }
                    else{
                        Eq3[i-1] = 0;
                    }
            }

                for(i=(N-2);i>=0;i--){
                    if(Eq3[i]!=0 && i!=0){
                        printf("%dX(%d)",Eq3[i],i);
                    }
                    if(i>=1 && Eq3[i]!=0){
                        printf(" + ");
                    }
                    if (Eq3[i]!=0 && i==0){
                        printf("%d",Eq3[i]);
                }
            }
    }if(N==2){
        printf("\n2 Derivada: %d",Eq2[1]);
    }


    if(N==2){
        S = (-Eq[1])/Eq[2];
        P = Eq[0] / Eq[2];
        AcharSP(S,P,&x1,&x2);
    }
    if(N==3){
        S = (-Eq2[1])/Eq2[2];
        P = Eq2[0] / Eq2[2];
        AcharSP(S,P,&x1,&x2);
    }
    printf("\n\nS = %d\nP = %d\n",S,P);
    printf("(%d;%d)",x1,x2);

    if(N==2){
        MLx = (float)(-Eq2[0]) / (float)Eq2[1];
        MLy = Eq[2]*(MLx*MLx) + Eq[1]*MLx + Eq[0];
        printf("\n\nGrafico da F(%.1f) = %.1f",MLx, MLy);

        if(Eq[2]>0){
            printf("\nx1(%d) e maximo local e x2(%d) e minimo local",x1,x2);
        }
        else{
            printf("\nx1(%d) e minimo local e x2(%d) e maximo local",x1,x2);
        }
        printf("\n\n\nCriterio da segunda derivada: \n");
        if(Eq3[0]>0){
            ;
            printf("Entao o critico e maximo local\n\n");
        }
        else{
            printf("Entao o critico e minimo local\n\n");

        }
    }

    if(N==3){
            float F[3];
        if(Eq[3]>0){
            printf("\nx1(%d) e maximo local e x2(%d) e minimo local",x1,x2);
        }
        else{
            printf("\nx1(%d) e minimo local e x2(%d) e maximo local",x1,x2);
        }

        F[2] = Eq[3] * 0 + Eq[2] * 0 + Eq[1] * 0 + Eq[0];
        F[1] = Eq[3] * x1 + Eq[2] * x1 + Eq[1] * x1 + Eq[0];
        F[0] = Eq[3] * x2 + Eq[2] * x2 + Eq[1] * x2 + Eq[0];

        printf("\n\nF(0) = %d\n",F[2]);
        printf("F(%d) = %.1f\n",x1,F[1]);
        printf("F(%d) = %.1f\n",x2,F[0]);
    }
    
    system("pause");
    return 0;
}

void AcharSP(int S ,int P, int *x1, int *x2){
    int i,j;
    for (i=-30;i<=20;i++){
        for(j=-30;j<=20;j++){
            if((i+j)==S && (i*j)== P){
                    if(j>i){
                       *x1 = i;
                       *x2 = j;
                    }
                    else{
                    *x1 = j;
                    *x2 = i;
                }
            }
        }
    }
}
