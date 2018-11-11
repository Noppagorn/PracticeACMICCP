//p11244.c

#include <stdio.h>
#include <stdbool.h>

int count_star(int star[][2],int topStar){
    int count = 0;
    bool check = true;
    for (int i = 0 ; i <= topStar;i++){
        for (int j = 0 ; j <= topStar;j++){
            if ((star[i][0] == star[j][0] -1 && star[i][1] == star[j][1] - 1)
            || (star[i][0] == star[j][0] && star[i][1] == star[j][1] - 1) 
            || (star[i][0] == star[j][0]+1 && star[i][1] == star[j][1] - 1) 

            || (star[i][0] == star[j][0]-1 && star[i][1] == star[j][1]) 
            || (star[i][0] == star[j][0]+1 && star[i][1] == star[j][1]) 

            || (star[i][0] == star[j][0]-1 && star[i][1] == star[j][1] + 1) 
            || (star[i][0] == star[j][0] && star[i][1] == star[j][1] + 1) 
            ||(star[i][0] == star[j][0]+1 && star[i][1] == star[j][1] + 1) ){
                //printf("%d %d \n",star[i][0],star[i][1]);
                check = false;
                break;
            }

        }
        if (check){
            count++;
        }
        check = true;

    }
    return count ;
}

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
                    star[topStar][1] = j+1; 
                }
            }
        }
        if (row == 0 && column == 0)break;
        printf("%d\n",count_star(star,topStar));
        topStar = -1;
    }

    return 0;
}