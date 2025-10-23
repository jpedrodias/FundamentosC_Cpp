#include <stdio.h>

int main(){

    const char historico1[2][10] = {
        "Depósi.",
        "Levant.",
    };

    const char *historico2[] = {
        "Depósi.",
        "Levant.",
    };


    for(int i = 0; i < 2; i++){
        printf("historico1[%d]: %s\n", i, historico1[i]);
    }

    for(int i = 0; i < 2; i++){
        printf("historico2[%d]: %s\n", i, historico2[i]);
    }

    return 0;
}