#include <cstdio>
#include <list>

using namespace std;

#define ONE 0
#define TWO 1

list<char> player[2], middle;

void takeMiddle(list<char> & user) {
        for (list<char>::reverse_iterator it = middle.rbegin(); it != middle.rend(); it++) {
                user.push_back(*it);
        }
        middle.clear();
}

// return the number of card draws
int drawCards(list<char> & user, int n, int * faceCover) {
    *faceCover = NULL;

    for (int i = 0; i < n; i++) {
        if (user.empty()) {
            return i;
        }
        char tmp = user.front();
        user.pop_front();
        middle.push_front(tmp);
        switch (tmp) {
        case 'J': *faceCover = 1; return -1;
        case 'Q': *faceCover = 2; return -1;
        case 'K': *faceCover = 3; return -1;
        case 'A': *faceCover = 4; return -1;
        }
    }
    return n;
}

void play()
{
    int curr = TWO;
    int numDraw = 1, needToCover, x;
    int lastFace = -1;

    while (1) {
        if (player[curr].empty()) {
            int win = (curr^1);
            printf("%d %2d\n", win + 1, player[win].size());
            break;
        } else {
            x = drawCards(player[curr], numDraw, &needToCover);
            if (needToCover == NULL) {
                if (x < numDraw) {
                    // current guy lost
                    continue;
                }

                if (lastFace > -1) {
                    lastFace = -1;
                    takeMiddle(player[curr^1]);
                }
                numDraw = 1;
            } else {
                lastFace = curr;
                numDraw = needToCover;
            }
            curr ^= 1;
        }
    }
}

int main()
{
    int i, j, k, scan;
    char ch[10];
    while (1) {
        scanf("%s", ch);
        if (ch[0] == '#') {
            break;
        }

        player[0].clear();
        player[1].clear();
        middle.clear();
        scan = 0;
        k = TWO;
        for (i = 1; i <= 52; i++) {
            if (scan) {
                scanf("%s", ch);
            }
            player[k].push_front(ch[1]);
            k ^= 1;
            scan = 1;
        }

        play();
    }
    return 0;
}
