#include<stdlib.h>

//定义一个结构体； 
//del：表示第二只老鼠对应得分 - 第一只老鼠对应的分
//index：表示对应的下标
typedef struct {
    int del;
    int index;

}arr;


//作为库函数 qsort 的比较函数参数
int compar(void* a, void* b)
{
    return ((*(arr*)a).del - (*(arr*)b).del);
}


//解决问题主函数
int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k) {
    int i = 0;      //作为循环变量使用
    int score = 0;  //记录吃奶酪的得分

    //开辟和奖励数组等长的 结构体数组 空间复杂度O(n)
    arr* res = (arr*)malloc(sizeof(arr) * reward1Size);

    //对结构体数组进行赋值 时间复杂度O(n)
    for (; i < reward1Size; i++)
    {
        res[i].del = reward2[i] - reward1[i];
        res[i].index = i;

    }

    //对结构体数组进行排序 时间复杂度O(n*logn)
    qsort(res, reward1Size, sizeof(arr), compar);

    //对排序后的前k个奶酪，是老鼠1的奖励，追加得分
    for (i = 0; i < k; i++)
    {
        score += reward1[res[i].index];
    }

    //对排序后的第k+1~reward1Size个奶酪，是老鼠2的奖励，追加的分
    while (i < reward1Size)
    {
        score += reward2[res[i].index];
        i++;
    }

    //释放开辟的空间
    free(res);
    res = NULL;

    //返回最终最大得分
    return score;
}
