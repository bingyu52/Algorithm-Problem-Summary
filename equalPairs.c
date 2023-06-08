//这是一个O（n^3）的算法，暂时未想到更好的解法

int equalPairs(int** grid, int gridSize, int* gridColSize){
    int count = 0 ;     //记录相等行列的对数
    int i=0 , j=0 , k=0 ;   //作为循环变量
    for(i=0;i<gridSize;i++)     //每一行
    {
        for(j=0;j<gridSize;j++)     //每一列
        {
            for(k=0; k<gridSize;k++)        //每一个数比较
            {
                //如果行 和 列 的值 不同 ，则退出此循环
                if(grid[i][k] != grid[k][j])
                {
                    break;
                }

            }
            //如果i行和j列的值全部相等，则累计
            if(k==gridSize)
            {
                count++;
            }
        }

    }
    return count;
}
