// Online C compiler to run C program online
#include <stdio.h>

int main() {
    float s = -0.5, o = 0;
    for (s; s<1.5; s+=0.2) {
        if (s<=0.0) {
            o = 0.0;
        } else if (s<=1.0) {
            o = s;
        } else {
            o = 1.0;
        }
        printf("Clumping [%f] : %f\n", s, o);
    }
    return 0;
}