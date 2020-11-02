#ifndef LEXER_H
#define LEXER_H
//includes the token header for access to token
#include "token.h"
//makes a data structurw lexer_structure and renames it lexer_T
typedef struct LEXER_STRUCT{
    //char c stands for the current character the lexer is on
    char c;
    //stands for the index in the contents array so we can loop through
    unsigned int i;
    //is the contents to run through the lexer
    char* contents;
}lexer_T;

//all methods exdept init_lexer takes in the lexer to perform the operation on
//initialize the lexer with the contents to parse and returns the lexer
lexer_T* init_lexer(char* contents);
//advances the lexer one character in the contents array
void lexer_advance(lexer_T* lexer);
//skips over all whitespace
void lexer_skip_whitespace(lexer_T* lexer);
//logic that gets the token and returns it 
token_T* lexer_get_next_token(lexer_T* lexer);
//this is the logic for making a string and returning the string token
token_T* lexer_collect_string(lexer_T* lexer);
//allows you to advance the lexer one char and return the token it is passed in one go
token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token);
//returns the token id 
token_T* lexer_collect_id(lexer_T* lexer);
//gets the current character as a string or character array
char* lexer_get_current_char_as_string(lexer_T* lexer);
#endif