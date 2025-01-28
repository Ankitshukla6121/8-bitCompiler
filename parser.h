#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    NODE_VAR_DECL, NODE_ASSIGN, NODE_ARITH_OP, NODE_CONDITIONAL
} NodeType;

typedef struct ASTNode {
    NodeType type;
    struct ASTNode* left;
    struct ASTNode* right;
    char text[MAX_TOKEN_LEN];
} ASTNode;

ASTNode* createNode(NodeType type, char* text);
ASTNode* parse(FILE *file);
void printAST(ASTNode* node, int depth);

#endif
