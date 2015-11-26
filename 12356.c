#include <stdio.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct node nodes[100002];

void init(int n)
{
    int i;
    for (i = 1; i <= n; i++) {
        nodes[i].num = i;
        nodes[i].left = &nodes[i-1];
        nodes[i].right = &nodes[i+1];
    }
    nodes[1].left = NULL;
    nodes[n].right = NULL;
}

int main()
{
    int i, j, k, nums, kills;
    while (1) {
        scanf("%d %d", &nums, &kills);
        if (!nums) break;

        init(nums);
        for (i = 0; i < kills; i++) {
            scanf("%d %d", &j, &k);
            if (nodes[j].left == NULL) {
                printf("* ");
                if (nodes[k].right) (nodes[k].right)->left = NULL;
            } else {
                printf("%d ", nodes[j].left->num);
                if (nodes[k].right) (nodes[k].right)->left = nodes[j].left;
            }

            if (nodes[k].right == NULL) {
                printf("*\n");
                if (nodes[j].left) (nodes[j].left)->right = NULL;
            } else {
                printf("%d\n", nodes[k].right->num);
                if (nodes[j].left) (nodes[j].left)->right = nodes[k].right;
            }
        }
        puts("-");

    }
    return 0;
}
