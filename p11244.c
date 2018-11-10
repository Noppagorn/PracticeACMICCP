//p11244.c

#include <stdio.h>


int main(){
    int row = -1,column = -1;
    char line[101];
    int star[100][2];
    int topStar = -1;
    while (row != 0 && column != 0){
        scanf("%d %d",&row,&column);
        for(int i = 0 ; i <= row;i++){
            gets(line);
            for (int j = 0 ; line[j] != '\0';j++){
                if (line[j] == '*'){
                    topStar++;
                    star[topStar][0] = i;
                    star[topStar][1] = j; 
                }
            }
        }
        //out line
        for (int i = 0 ; i <= topStar;i++){
            //printf("%d %d\n",star[i][0],star[i][1]);

        }
    }

    // for (int i = 0 ; i <= topStar;i++){
    //     //printf("%d %d\n",star[i][0],star[i][1]);
    // }

    return 0;
}