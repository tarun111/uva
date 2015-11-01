#include <stdio.h>

int main()
{
    int n, i;
    typedef enum {XP, XN, YP, YN, ZP, ZN} dir;
    dir current;
    char ch[4];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        current = XP;
        for (i = 1; i < n; i++) {
            scanf("%s", ch);

            if (ch[0] == 'N') continue;

            if (ch[1] == 'y' && ch[0] == '+') {
                switch (current) {
                    case XP: current = YP; break;
                    case YP: current = XN; break;
                    case XN: current = YN; break;
                    case YN: current = XP; break;
                }
            } else if (ch[1] == 'y' && ch[0] == '-') {
                switch (current) {
                    case XP: current = YN; break;
                    case YN: current = XN; break;
                    case XN: current = YP; break;
                    case YP: current = XP; break;
                }
            } else if (ch[1] == 'z' && ch[0] == '+') {
                switch (current) {
                    case XP: current = ZP; break;
                    case ZP: current = XN; break;
                    case XN: current = ZN; break;
                    case ZN: current = XP; break;
                }
            } else if (ch[1] == 'z' && ch[0] == '-') {
                switch (current) {
                    case XP: current = ZN; break;
                    case ZN: current = XN; break;
                    case XN: current = ZP; break;
                    case ZP: current = XP; break;
                }
            }
        }

        switch (current) {
            case XP: puts("+x"); break;
            case XN: puts("-x"); break;
            case YP: puts("+y"); break;
            case YN: puts("-y"); break;
            case ZP: puts("+z"); break;
            case ZN: puts("-z"); break;
        }
    }
    return 0;
}
