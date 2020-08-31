/* 用两个栈实现一个队列。
队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
*/

#include <stdio.h>
#include <stdlib.h>

/* typedef struct
{
    int len;
    int top1;
    int top2;
    int *s1;
    int *s2;

} CQueue;

CQueue *cQueueCreate()
{
    CQueue *cq = (CQueue *)malloc(sizeof(CQueue));
    cq->len = 10000;
    cq->top1 = -1;
    cq->top2 = -1;
    cq->s1 = (int *)calloc(cq->len, sizeof(int));
    cq->s2 = (int *)calloc(cq->len, sizeof(int));
    return cq;
}

void cQueueAppendTail(CQueue *obj, int value)
{
    if(obj->top1 == -1)
    {
        while(obj->top2 > -1)
        {
            obj->s1[++obj->top1] = obj->s2[obj->top2--];
        }
    }
    obj->s1[++obj->top1] = value;
}

int cQueueDeleteHead(CQueue *obj)
{
    if(obj->top2 == -1)
    {
        while(obj->top1 > -1)
        {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }

    return obj->top2 == -1 ? -1 : obj->s2[obj->top2--];
}

void cQueueFree(CQueue *obj)
{
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
 */

#define MaxSize 1000
typedef struct
{
    int in_top;      //指示有无新进入队列的元素
    int out_top;     //指示pop_stack是否需要更新
    int *push_stack; //保存插入队列的元素的栈
    int *pop_stack;  //逆序保存上个栈的元素
} CQueue;

CQueue *cQueueCreate()
{
    CQueue *obj = (CQueue *)malloc(sizeof(CQueue));
    obj->pop_stack = (int *)malloc(MaxSize * sizeof(int));
    obj->push_stack = (int *)malloc(MaxSize * sizeof(int));
    obj->in_top = -1;
    obj->out_top = -1;
    return obj;
}

void cQueueAppendTail(CQueue *obj, int value)
{
    obj->push_stack[++(obj->in_top)] = value; //插入新入栈的元素
}

int cQueueDeleteHead(CQueue *obj)
{
    if (obj->out_top == -1)
    {   //上一次的push_stack元素已经全部delete了，故需要导入 新入栈的元素
        //(即为更新)
        if (obj->in_top == -1)
        { //在此期间没有新入栈的元素
            return -1;
        }
        while (obj->in_top > -1)
        { //装入元素，并将push_stack清空
            obj->pop_stack[++(obj->out_top)] = obj->push_stack[obj->in_top--];
        }
    }
    return obj->pop_stack[(obj->out_top)--]; //删除
}

void cQueueFree(CQueue *obj)
{
    free(obj->push_stack);
    free(obj->pop_stack);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);

 * int param_2 = cQueueDeleteHead(obj);

 * cQueueFree(obj);
*/


int main()
{
    return 0;
}