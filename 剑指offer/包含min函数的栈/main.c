/* 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

提示：
各函数的调用总次数不超过 20000 次
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int min;
    int buff[20000];

} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
    MinStack *s = (MinStack *)malloc(sizeof(MinStack));
    memset(s->buff, 0, sizeof(s->buff));
    s->top = s->min = 0;
    return s;
}

void minStackPush(MinStack *obj, int x)
{
    obj->buff[obj->top] = x;
    if(obj->top == 0)
        obj->min = x;
    else if(obj->min > x)
        obj->min = x;
    obj->top++;
}

void minStackPop(MinStack *obj)
{
    --obj->top;
    if(obj->top < 0)
        obj->top = 0;
    obj->min = obj->buff[0];
    for(int i = 0; i < obj->top; i++)
    {
        if(obj->min > obj->buff[i])
            obj->min = obj->buff[i];
    }
}

int minStackTop(MinStack *obj)
{
    return obj->buff[obj->top-1];
}

int minStackMin(MinStack *obj)
{
    return obj->min;
}

void minStackFree(MinStack *obj)
{
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackMin(obj);

 * minStackFree(obj);
*/

int main()
{

    return 0;
}