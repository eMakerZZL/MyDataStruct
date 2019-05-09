/**
 * @file test_stack.c
 * @brief 顺序栈测试文件
 * @author ZhangZL
 * @version 1.0
 * @date 2019-05-09
 */
#include "unity.h"
#include "stack.h"

static stack_t stack;    

void setUp(void)
{
    init_stack(&stack);
}

void tearDown(void)
{
}

void test_stack_AfterInitStackIsRight(void)
{
    TEST_ASSERT_EACH_EQUAL_UINT32(0,stack.data,MAX_STACK_SIZE);
    TEST_ASSERT_EQUAL_INT32(-1,stack.length);
}

void test_stack_PushOneDataInStack(void)
{
    push(&stack,100);

    TEST_ASSERT_EQUAL_UINT32(100,stack.data[0]);
}

void test_stack_PushMultDataInStack(void)
{
    push(&stack,100);
    push(&stack,200);
    push(&stack,300);

    TEST_ASSERT_EQUAL_UINT32(100,stack.data[0]);
    TEST_ASSERT_EQUAL_UINT32(200,stack.data[1]);
    TEST_ASSERT_EQUAL_UINT32(300,stack.data[2]);
}

void test_stack_PopOneDataInStack(void)
{
    element val1;

    push(&stack,100);
    pop(&stack,&val1);

    TEST_ASSERT_EQUAL_UINT32(100,val1);
    TEST_ASSERT_EQUAL_UINT32(0,stack.data[0]);
    TEST_ASSERT_EQUAL_INT32(-1,stack.length);
}

void test_stack_PopMultDataInstack(void)
{
    element val1;
    element val2;
    element val3;

    push(&stack,100);
    push(&stack,200);
    push(&stack,300);

    pop(&stack,&val1);
    pop(&stack,&val2);
    pop(&stack,&val3);

    TEST_ASSERT_EQUAL_UINT32(300,val1);
    TEST_ASSERT_EQUAL_UINT32(200,val2);
    TEST_ASSERT_EQUAL_UINT32(100,val3);
}

void test_stack_PushDataOverflowWasNoHarm(void)
{
    TEST_ASSERT_TRUE(push(&stack,100));
    TEST_ASSERT_TRUE(push(&stack,200));
    TEST_ASSERT_TRUE(push(&stack,300));
    TEST_ASSERT_TRUE(push(&stack,100));
    TEST_ASSERT_TRUE(push(&stack,200));
    TEST_ASSERT_FALSE(push(&stack,300));
}

void test_stack_PopDataOverfloseWasNoHarm(void)
{
    element val;

    TEST_ASSERT_FALSE(pop(&stack,&val));
    TEST_ASSERT_FALSE(pop(&stack,&val));
    TEST_ASSERT_FALSE(pop(&stack,&val));
    TEST_ASSERT_FALSE(pop(&stack,&val));
    TEST_ASSERT_FALSE(pop(&stack,&val));
    TEST_ASSERT_FALSE(pop(&stack,&val));
}
