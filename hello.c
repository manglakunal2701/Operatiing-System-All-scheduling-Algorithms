#include<stdio.h>
int main(){
    printf("HELLO GUYS");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int z=0;z<5;z++){
                printf("%d%d%d ",i,j,z);
            }
        }
    }
    return 0;
}
