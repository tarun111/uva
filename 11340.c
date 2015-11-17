#include <stdio.h>

int main()
{
    int cases, i, j, k,len;
    int map[256];
    unsigned char line[10006], ch;
    long long price;

    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &j);
        for (i = 0; i < 256; i++) map[i] = 0;
        price = 0;

        for (i = 0; i < j; i++) {
            getchar();
            ch = getchar();
            scanf("%d",&k);
            map[ch] = k;
        }

        scanf("%d", &j);
        getchar();
        while(j--) {
            gets(line);
            for (i = 0; line[i] != '\0'; i++) {
                price += map[line[i]];
            }
        }

        printf("%01.2lf$\n", price/100.0);
    }
    return 0;
}
