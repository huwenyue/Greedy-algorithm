#include<cstdio>
int main(){
    int count[10];  //记录数字0-9的个数
    for(int i=0;i<10;i++){
        scanf("%d",&count[i]);
    }
    for (int i=1; i<10; i++) {
        //从1-9中选择count不为0的最小数字
        if(count[i] > 0){
            printf("%d",i);  //输出最小的数字
            count[i] --; //该数字的个数-1
            break; //找到一个后就中断
        }
    }
    for(int i=0;i<10;i++){ //从0-9输出对应个数的数字
        for(int j=0;j<count[i];j++){
            printf("%d\n",i);
        }
    }
    return 0;
}
