#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tokenize.c
typedef enum
{
  TK_RESERVED,
  TK_NUM,
  TK_EOF,
} TokenKind;

// Token type
typedef struct Token Token;
struct Token
{
  TokenKind kind;
  Token *next;
  long val;
  char *str;
  int len;
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
void expect(char *op);
long expect_number(void);
bool at_eof(void);
Token *tokenize(void);

extern char *user_input;
extern Token *token;

// parse.c
typedef enum
{
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // Integer
} NodeKind;

typedef struct Node Node;
struct Node
{
  NodeKind kind;
  Node *next;
  Node *lhs;
  Node *rhs;
  long val;
};

Node *program(void);

// codegen.c
void codegen(Node *node);
