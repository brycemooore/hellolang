#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

lexer_T* init_lexer(char* contents){
    //allocates memory for lexer
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    //contents is string to parse
    lexer->contents = contents;
    //i is index of character so set it to 0
    lexer->i = 0;
    //makes c the first character in the contents array because i is 0
    lexer->c = contents[lexer->i];
    //returns the lexer
    return lexer;
    //lexer->c is the same as lexer*.c
}

void lexer_advance(lexer_T* lexer){
    //checks if the current character is null and if there are more characters to go
    //if so it can advance by increasing index and changing c to the new character at new index
    if(lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        lexer-> i += 1;
        lexer->c = lexer->contents[lexer->i];
    }
}

//loops and checks so that while the current character is whitespace
void lexer_skip_whitespace(lexer_T* lexer){
    while(lexer->c == ' ' || lexer->c == 10){
        lexer_advance(lexer);
    }
}

token_T* lexer_get_next_token(lexer_T* lexer){
    while(lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        if (lexer->c == ' ' || lexer->c == 10){
            lexer_skip_whitespace(lexer);
        }
        if(isalnum(lexer->c)){
            return lexer_collect_id(lexer);
        }
        if(lexer->c == '"'){
            return lexer_collect_string(lexer);
        }
        switch(lexer->c){
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer))); break;
        }
    }
    return (void*)0;
}

token_T* lexer_collect_string(lexer_T* lexer){

    lexer_advance(lexer);
    
    char* value = calloc(1, sizeof(char));
    value[0] ='\0';

    while(lexer->c != '"'){
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, strlen(value) + strlen(s) + 1 * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }
    lexer_advance(lexer);
    return init_token(TOKEN_STRING, value);
}

char* lexer_get_current_char_as_string(lexer_T* lexer){
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    return str;
}

token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token){
    lexer_advance(lexer);
    return token;
}

token_T* lexer_collect_id(lexer_T* lexer){

    char* value = calloc(1, sizeof(char));
    value[0] ='\0';

    while(isalnum(lexer->c)){
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, strlen(value) + strlen(s) + 1 * sizeof(char));
        strcat(value, s);

        lexer_advance(lexer);
    }
    return init_token(TOKEN_ID, value);
}