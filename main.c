#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char s[30];char c[30];int b;} Abc;void b(const char*p){FILE*t;char l[30];char a[30];int n;int e=0;t=fopen("t.txt","r");if(t==NULL){puts("Erro arquivo.");return;}while(!feof(t)){if(fscanf(t,"%29s\n%29s\n%d\n\n",l,a,&n)==3){if(strcmp(l,p)==0){printf("\nEncontrado:\n%s\n%s\n%d\n",l,a,n);e=1;break;}}}fclose(t);if(e==0){printf("\n'%s' nao encontrado.\n",p);}}int main(void){Abc abc;FILE*t;int x;printf("1.Add\n2.Busca\n:");scanf("%d",&x);switch(x){case 1:printf("titulo:");scanf("%29s",abc.s);printf("autor:");scanf("%29s",abc.c);printf("ano:");scanf("%d",&abc.b);t=fopen("t.txt","a");if(t==NULL)return 1;fprintf(t,"%s\n%s\n%d\n\n",abc.s,abc.c,abc.b);fclose(t);printf("Ok\n");break;case 2:;char B[30];printf("\nBusca:");scanf("%29s",B);b(B);break;default:printf("Erro\n");break;}return 0;}

printf("ola, estou aprendendo sobre branch");