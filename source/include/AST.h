#ifndef AST_H;
#define AST_H;

typedef struct AST_STRUCT{
    enum{
        AST_FUNCTION_CALL,
        AST_VARIABLE,
        AST_VARIABLE_DEFINITION,
        AST_STRING
    } type;

    //ast variable definition
    char* variable_definition_variable_name;
    struct AST_STRUCT* variable_definition_value;

    //ast variable
    char* variable_name;

    //ast function call
    char* function_call_name;
    struct AST_STRUCT** function_call_arguments;
    // size_t function__call_arguments_size;

} AST_T;
#endif