#ifndef OPERATION_H
#define OPERATION_H

#include <stdint.h>

enum op_e {
    // control
    HTL,
    JMP,
    CJMP,
    OJMP,
    CALL,
    RET,
    // stack
    PUSH,
    POP,
    // data access
    LOADB,
    LOADW,
    STOREB,
    STOREW,
    LOADI,
    NOP,
    // i/o
    IN,
    OUT,
    // arithmetic
    ADD,
    ADDI,
    SUB,
    SUBI,
    MUL,
    DIV,
    // bitwise
    AND,
    OR,
    NOR,
    NOTB,
    SAL,
    SAR,
    // logic
    EQU,
    LT,
    LTE,
    NOTC
    // fake op
    // BYTE
    // WORD
};

struct op_t1 {
    unsigned op : 5;
    unsigned pad : 27;
};

struct op_t2 {
    unsigned op : 5;
    unsigned pad : 3;
    unsigned addr : 24;
};

struct op_t3 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned pad : 24;
};

struct op_t4 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned addr : 24;
};

struct op_t5 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned pad : 8;
    unsigned imme : 16;
};

struct op_t6 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned pad : 16;
    unsigned port : 8;
};

struct op_t7 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned reg1 : 4;
    unsigned reg2 : 4;
    unsigned pad : 16;
};

struct op_t8 {
    unsigned op : 5;
    unsigned reg0 : 3;
    unsigned reg1 : 4;
    unsigned pad : 20;
}

union op_u {
    uint32_t litera;
    struct op_t1 t1;
    struct op_t2 t2;
    struct op_t3 t3;
    struct op_t4 t4;
    struct op_t5 t5;
    struct op_t6 t6;
    struct op_t7 t7;
    struct op_t8 t8;
};

#endif
