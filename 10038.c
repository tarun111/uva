#include <stdio.h>
int main()
{
    int n, i, j, k, diff;
    int arr[3000];

    while (scanf("%d", &n)>0) {
        for (i = 1; i < n; i++) arr[i] = 0;

        scanf("%d", &j);
        for (i = 1; i < n; i++) {
            scanf("%d", &k);
            diff = k - j;
            if (diff < 0) diff = -diff;
            if (diff < n) arr[diff] = 1;
            j = k;
        }

        j = 1;
        for (i = 1; i < n; i++) if (arr[i] != 1) {j = 0; break;}
        if (j) puts("Jolly");
        else puts("Not jolly");
    }
    return 0;
}
