/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE (100)
#define ASSERT(val)   \
	do { \
		 if (!val) \
			printf("fatal error %s %d\n", __func__, __LINE__); \
	} while (0)

enum operator {
	initial,
	add,
	minus,
	multiplication,
	division,
	max
};

static double value_stack[MAX_INPUT_SIZE];
static ssize_t value_stack_pointer;

static char op_stack[MAX_INPUT_SIZE];
static ssize_t op_stack_pointer;

static int pop_value_stack(double *val)
{
	if (value_stack_pointer <= 0) {
		ASSERT(0);
		return -1;
	}

	*val = value_stack[--value_stack_pointer];

	return 0;
}

static int push_value_stack(double val)
{
	if (value_stack_pointer >= MAX_INPUT_SIZE) {
		ASSERT(0);
		return -1;
	}

	value_stack[value_stack_pointer++] = val;

	return 0;
}

static int pop_op_stack(char *op)
{
	if (op_stack_pointer <= 0)
		return -1;

	*op = op_stack[--op_stack_pointer];

	return 0;
}

static int push_op_stack(char op)
{
	if (op_stack_pointer >= MAX_INPUT_SIZE) {
		ASSERT(0);
		return -1;
	}

	op_stack[op_stack_pointer++] = op;

	return 0;
}

static char peek_op_stack(void)
{
	if (!op_stack_pointer)
		return '\0';

	return op_stack[op_stack_pointer - 1];
}

static void print_op_stack(void)
{
	ssize_t i;

	printf("current op stack is:\n");
	for (i = op_stack_pointer - 1; i >= 0; i--)
		printf("%c\n", op_stack[i]);
}

static void print_value_stack(void)
{
	ssize_t i;

	printf("current value stack is:\n");
	for (i = value_stack_pointer - 1; i >= 0; i--)
		printf("%lf\n", value_stack[i]);
}

static int get_operator_priority(enum operator op)
{
	switch (op) {
	case add:
		return 1;
	case minus:
		return 1;
	case multiplication:
		return 2;
	case division:
		return 2;
	case initial:
		return 0;
	default:
		ASSERT(0);
		return 0;
	}
}

static enum operator get_operator(char c)
{
	switch (c) {
	case '+':
		return add;
	case '-':
		return minus;
	case 'x':
		return multiplication;
	case '/':
		return division;
	case '\0':
		return initial;
	default:
		ASSERT(0);
		return max;
	}
}

static bool is_operator(char c)
{
	switch (c) {
	case '+': return true;
	case '-': return true;
	case 'x': return true;
	case '/': return true;
	default: return false;
	}
}

static void  compute_result(enum operator op)
{
	double val1, val2, result;

	switch(op) {
	case add:
		pop_value_stack(&val1);
		pop_value_stack(&val2);
		result = val1 + val2;
		push_value_stack(result);
		break;
	case minus:
		pop_value_stack(&val1);
		pop_value_stack(&val2);
		result = val2 - val1;
		push_value_stack(result);
		break;
	case multiplication:
		pop_value_stack(&val1);
		pop_value_stack(&val2);
		result = val2 * val1;
		push_value_stack(result);
		break;
	case division:
		pop_value_stack(&val1);
		pop_value_stack(&val2);
		if (val2)
			result = val2 / val1;
		else
			ASSERT(0);
		push_value_stack(result);
		break;
	default: ASSERT(0);
	}

	printf("result is %lf push %lf to value stack\n", result, result);
}

static double collapse_stacks(void)
{
	char c;
	int status;
	double result = 0;

	printf("end of input collapse both op and value stacks\n");
	print_op_stack();
	print_value_stack();

	while (!(status = pop_op_stack(&c)))
		compute_result(get_operator(c));

	status = pop_value_stack(&result);
	if (status) {
		ASSERT(0);
		return -1.0;
	}

	return result;
}

static void handle_operator(char c)
{
	int status = 0;
	char c_peek = peek_op_stack();
	enum operator op1 = get_operator(c);
	enum operator op2 = get_operator(c_peek);

	printf("op1 is : %c op2 is : %c\n", c, c_peek);
	if ((get_operator_priority(op1)) <= 
		get_operator_priority(op2)) {
		printf("%c is of lower/equal priority than %c hence pop op stack and compute result\n",
			c, c_peek);
		status = pop_op_stack(&c_peek);
		if (status) {
			ASSERT(0);
			return;
		}
		compute_result(get_operator(c_peek));
	} else {
		printf("%c is of higher priority than %c hence only push it to op stack\n",
			c, c_peek);
	}
	push_op_stack(c);
}

static double calculator(char *argv[], int limit)
{
	char c;
	int i;

	for (i = 1; i < limit; i++) {
		c = *argv[i];
		printf("argv[%d] is %s\n", i, argv[i]);
		if (isdigit(c)) {
			printf("push %s to value stack\n", argv[i]);
			push_value_stack(atoi(argv[i]));
		} else if (is_operator(c)) {
			printf("push %s to op stack\n", argv[i]);
			handle_operator(*argv[i]);
		} else {
			printf("error : unexpected input");
			return -1.0;
		}
	}

	return collapse_stacks();
}

static void print_argv(char *argv[], int argc)
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s ", argv[i]);
}

int main(int argc, char *argv[])
{
	double result;

	if (argc < 2) {
		printf("invalid format: calcolator val operator val and so on\n");
	}

	result = calculator(argv, argc);
	printf("result of: ");
	print_argv(argv, argc);
	printf("is %lf\n", result);

	return 0;
}
