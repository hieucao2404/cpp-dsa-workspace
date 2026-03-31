// The idea is that the recuresice fucntion f outght to be expressible ony a few lines, just like nonrecuresive funciton

// Line 3 and 4 in this function below is known as base case, taht is value for which the function is directly known withou resorting to recursion.
#include <cstdio>
int f(int x) {
    if (x == 0){
        return 0;
    }
    else {
        return 2 * f(x - 1) + x * x;
    }
}



int main(void){
    int x = 2;
    f(x);
    printf("%d", f(x));
    return 0;
}
