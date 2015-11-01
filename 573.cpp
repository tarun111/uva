#include<cstdio>

using namespace std;
int fail;

//handled: 100 50 5 99
int compute(double curr, int well, int days, double inc, double dec, double reduction) {
    if (inc < 0) {
        inc = 0;
    }
    curr += inc;
    if(curr > well) {
        return days;
    }

    curr -= dec;
    if(curr < 0) {
        fail = 1;
        return days;
    }

    return compute(curr, well, days + 1, inc - reduction, dec, reduction);
}

int main() {
    int height, d_day, d_night, fatigue, days;
    double dist = 0, fatigueFactor;
    while(1) {
        scanf("%d %d %d %d", &height ,&d_day, &d_night, &fatigue);
        if(height == 0) {
            break;
        }

        fail = 0;
        fatigueFactor = (double)(fatigue * d_day) / 100;
        dist = 0;
        days = compute(dist, height, 1, d_day, d_night, fatigueFactor);
        if(fail) {
            printf("failure on day %d\n", days);
        } else {
            printf("success on day %d\n", days);
        }
    }
}
