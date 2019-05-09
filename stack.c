/**
 * @file stack.c
 * @brief 顺序栈的实现
 * @author ZhangZL
 * @version 1.0
 * @date 2019-05-09
 */
#include "stack.h"

/**
 * @brief 判断栈空间是否已满
 *
 * @param stack
 *
 * @return true 满 false 非满
 */
static bool is_full(stack_t *stack) {
    if(stack->length >= MAX_STACK_SIZE - 1) return true;
    else return false;
}

/**
 * @brief 判断栈空间是否为空
 *
 * @param stack
 *
 * @return true 空 false 非空
 */
static bool is_empty(stack_t *stack) {
    if (stack->length < 0) return true;
    else return false;
}

/**
 * @brief 初始化栈
 *
 * @param stack
 */
void init_stack(stack_t *stack) {
    memset(stack->data,0,sizeof(stack->data));
    stack->length = -1;
}

/**
 * @brief 向栈中压入一个元素
 *
 * @param stack
 * @param data
 *
 * @return true 成功 false 失败
 */
bool push(stack_t *stack,element data)
{
    if(is_full(stack)) return false;

    stack->data[++stack->length] = data;

    return true;
}

/**
 * @brief 弹出一个栈顶元素
 *
 * @param stack
 * @param pdata
 *
 * @return true 成功 false 失败
 */
bool pop(stack_t *stack,element *pdata)
{
    if (is_empty(stack)) return false;

    *pdata = stack->data[stack->length];
    stack->data[stack->length--] = 0;

    return true;
}
