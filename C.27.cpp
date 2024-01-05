# include <stdio.h>
# include <stdlib.h>
typedef struct
{
    int row, col;//三元组的行号，列号
    int item;//三元组的元素值
}Triple;
typedef struct
{
    Triple data[100];//非零元素数组
    int mu, nu, num;//稀疏矩阵的行数，列数，非零元素个数
}TSMatrix;

void InitTSMatrix(TSMatrix * pTSM, int m , int n)//初始化稀疏矩阵
{
    pTSM->mu = m;
    pTSM->nu = n;
    pTSM->num = 0;
}
int SetItem(TSMatrix * pTSM, int row, int col, int item)//添加三元组元素
{
    if(row > pTSM->mu || col > pTSM->nu)
        return 0;
    if(pTSM->num==100)
        return 0;
    if(item==0)
        return 1;
    int index = 0;
    while(index < pTSM->num)
    {
        if(row > pTSM->data[index].row)
            index++;
        else if(row == pTSM->data[index].row && col > pTSM->data[index].col)
            index++;
        else
            break;
    }
    if(row == pTSM->data[index].row && col == pTSM->data[index].col)
        pTSM->data[index].item = item;
    else
    {
        for(int i = pTSM->num; i > index; i--)
        {
            pTSM->data[i] = pTSM->data[i-1];
        }
        pTSM->data[index].row = row;
        pTSM->data[index].col = col;
        pTSM->data[index].item = item;
        pTSM->num++;
    }
    return 1;
}
void InputTSMatrix(TSMatrix * pTSM, int m , int n, int num)//输入三元组元素
{
    int row, col, item;
    for(int i = 1; i <= num; i++)
    {    
        printf("请输入稀疏矩阵的行数，列数，非零元素值:");
        scanf("%d %d %d", &row, &col, &item);
        if(item != 0)
        {
            if(SetItem(pTSM, row, col, item)==0)
            {
                printf("稀疏矩阵的行数或列数错误或三元组已满.\n");
                break;
            }
        }
    }
}
int GetItem(TSMatrix TSM, int row, int col)//根据行，列获取矩阵元素值
{
    if(row > TSM.mu || col > TSM.nu)
        return 0;
    for(int i = 0; i < TSM.num; i++)
    {
        if(row == TSM.data[i].row && col == TSM.data[i].col)
            return TSM.data[i].item;
    }
    return 0;
}
void ShowTriple(TSMatrix TSM)//输出三元组数组
{
    printf("输出三元组数组:\n");
    printf("Row\tCol\tItem\n");
    for(int i = 0; i < TSM.num; i++)
        printf("%d\t%d\t%d\n", TSM.data[i].row, TSM.data[i].col, TSM.data[i].item);
}
void ShowTSMatrix(TSMatrix TSM)//输出稀疏矩阵
{
    int index = 0;
    printf("输出稀疏矩阵:\n");
    for(int i = 1; i <= TSM.mu; i++)
    {    
        for(int j = 1; j <= TSM.nu; j++)
        {    
            if(i == TSM.data[index].row && j == TSM.data[index].col)
            {
                printf("%d\t", TSM.data[index].item);
                index++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
    printf("稀疏矩阵为%d行%d列，共%d个非零元素.\n\n", TSM.mu, TSM.nu, TSM.num);
}

int AddTSMatrix(TSMatrix A, TSMatrix B, TSMatrix * C)//稀疏矩阵的加法
{
    if(A.mu != B.mu || B.mu != C->mu || A.nu != B.nu || B.nu != C->nu)
        return 0;
    else
    {    
        for(int i = 1; i <= A.mu; i++)
        {
            for(int j = 1; j <= A.nu; j++)
            {
                int result = GetItem(A, i, j) + GetItem(B, i, j);
                if(result != 0)
                    SetItem(C, i, j, result );
            }
        }
        return 1;
    }
}

int MultiplyTSMatrix(TSMatrix A, TSMatrix B, TSMatrix * D)//稀疏矩阵的乘法
{
    if(A.nu != B.mu)
        return 0;
    else
    {    
        D->mu = A.mu;
        D->nu = B.nu;
        for(int i = 1; i <= A.mu; i++)
        {
            for(int j = 1; j <= B.nu; j++)
            {    
                int sum = 0;
                for(int k = 1; k <= A.nu; k++)
                {
                    sum += GetItem(A, i, k) * GetItem(B, k, j);
                }
                if(sum != 0)
                {
                    SetItem(D, i, j, sum);
                }
            }
        }
        return 1;
    }
}
int main(void)
{    
    int m , n, num;
    printf("请输入第一个稀疏矩阵的行数，列数，非零元素个数:");
    scanf("%d %d %d", &m, &n, &num);
    TSMatrix A;
    InitTSMatrix(&A, m, n);
    InputTSMatrix(&A, m , n, num);
    ShowTriple(A);
    ShowTSMatrix(A);

    printf("请输入第二个稀疏矩阵的行数，列数，非零元素个数:");
    scanf("%d %d %d", &m, &n, &num);
    TSMatrix B;
    InitTSMatrix(&B, m, n);
    InputTSMatrix(&B, m , n, num);
    ShowTriple(B);
    ShowTSMatrix(B);

    TSMatrix C;
    InitTSMatrix(&C, m, n);
    printf("两个稀疏矩阵相加以后.\n");
    if(AddTSMatrix(A, B, &C))
    {    
        ShowTriple(C);
        ShowTSMatrix(C);
    }
    else
    {
        printf("两个稀疏矩阵的行数或列数不相同,无法相加.\n");
    }

    TSMatrix D;
    InitTSMatrix(&D, m, n);
    printf("两个稀疏矩阵相乘以后.\n");
    if(MultiplyTSMatrix(A, B, &D))
    {
        ShowTriple(D);
        ShowTSMatrix(D);
    }
    else
    {
        printf("两个稀疏矩阵的行数或列数不相同,无法相乘.\n");
    }
    return 0;
}

