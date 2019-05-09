/**
 * @file stack.h
 * @brief 顺序栈
 * @author ZhangZL
 * @version 1.0
 * @date 2019-05-09
 */
#ifndef _STACK_H
#define _STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief 栈空间
 */
#define MAX_STACK_SIZE 5

/**
 * @brief 栈元素类型
 */
typedef unsigned int element;

/**
 * @brief 栈结构体
 */
typedef struct _stack_t {
    element data[MAX_STACK_SIZE];
    int32_t length;
} stack_t;

void init_stack(stack_t *stack);
bool push(stack_t *stack,element data);
bool pop(stack_t *stack,element *pdata);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // _STACK_H
