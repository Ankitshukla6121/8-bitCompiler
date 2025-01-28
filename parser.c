#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

ASTNode* createNode(NodeType type, char* text) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    strcpy(node->text, text);
    return node;
}

void printAST(ASTNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s\n", node->text);
    printAST(node->left, depth + 1);
    printAST(node->right, depth + 1);
}

ASTNode* parse(FILE* file) {
    Token token;
    getNextToken(file, &token);

    if (token.type == TOKEN_INT) {
        ASTNode* node = createNode(NODE_VAR_DECL, token.text);
        return node;
    }
    // Add parsing logic for other constructs
    return NULL;
}
