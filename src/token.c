//includes standard library and the file path for our token header

#include "include/token.h"
#include <stdlib.h>

//token_T* is a pointer and actually refers to the address where token_T is stored
//init token has two parameters, one being the type to set the token to and the other being the value
token_T* init_token(int type, char* value){
    //allocates memory? for the token to exist
    token_T* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    //sets the parameters to be the tokens attriubtes
    token->type = type;
    token->value = value;
    //returns token
    return token;
}