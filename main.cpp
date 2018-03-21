#include <cstdio>
#include <algorithm>
using namespace std;
struct mooncake{
    double store; //库存量
    double sell;  //总售价
    double price;  //单价
}cake[1010];
bool cmp(mooncake a,mooncake b){
    //单价从高到低排序
    return a.price > b.price;
}
int main(){
    int n;
    double D;
    scanf("%d%lf",&n,&D); //n为种类个数，D为总需求量，为double型
    for (int i=0; i<n; i++) {
        scanf("%lf",&cake[i].store);  //输入每种月饼的库存量
    }
    for (int i=0; i<n; i++) {
        scanf("%lf",&cake[i].sell);   //输入每种月饼的售价
        cake[i].price = cake[i].sell / cake[i].store ; //计算出单价
    }
    sort(cake, cake+n, cmp); //将单价从高到低排序
    double ans =0; //收益
    for (int i=0; i<n; i++) {
        if (cake[i].store <= D) {
            //若月饼库存量小于需求量
            D -= cake[i].store;  //将第i种月饼全部卖出
            ans +=cake[i].sell;   //收益增加
        }
        else{
            //若月饼库存量大于需求量
            ans += cake[i].price * D;
            break; //中断循环，否则会出错
        }
    }
    printf("%.2f\n",ans);  //精确到小数点后两位
    return 0;
    
}
