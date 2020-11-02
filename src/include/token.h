/*Creating a Token header in c to include the structure of what a token looks like and defines
what functions the token needs*/

//checks before compilation if TOKEN_H is defined
#ifndef TOKEN_H
//defines it if not
#define TOKEN_H

//creates like our own data type called TOKEN_STRUCT 
//typedef then renames it to be referenced as token_T
typedef struct TOKEN_STRUCT{
    //enum holds all of our possible tokens and names it type
    enum{
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
    }type;

    //the char array value which the token stands for
    char* value;
}token_T;

//a function to initialize a token found in token.c
token_T* init_token(int type, char* value);

#endif