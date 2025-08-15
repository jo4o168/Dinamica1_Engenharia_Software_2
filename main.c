#include <stdio.h>
typedef struct {char s[30];char c[30];
    int b;} Abc;
int main(void) {
    Abc abc;FILE *t;
    printf("titulo:");scanf("%s", abc.s);printf("autor:");scanf("%s", abc.c);printf("ano:");scanf("%d", &abc.b);t = fopen("t.txt", "a");
    if (t == NULL) {return 1;}fprintf(t, "%s\n%s\n%d\n\n", abc.s, abc.c, abc.b);fclose(t);
    return 0;
}