grammar M; 

program
    :   programSection* EOF
    ;

programSection                   
    :   classDeclaration
    |   functionDeclaration
    |   variableDeclaration
    ;

//------ Statement
statement
    :   blockStatement           
    |   expressionStatement
    |   selectionStatement
    |   iterationStatement
    |   jumpStatement
    ;

blockStatement
    :  '{' blockItem* '}'
    ;

blockItem
    : variableDeclaration
    | statement
    ;

expressionStatement
    :   expression? ';'
    ;

selectionStatement
    :   'if' '(' expression ')' statement ('else' statement)?
    ;

iterationStatement
    :   'while' '(' expression ')' statement 
    |   'for' '(' declinit=variableDeclaration
                  cond=expression? ';'
                  step=expression? ')'
            statement
    |   'for' '(' init=expression? ';'
                  cond=expression? ';'
                  step=expression? ')'
            statement
    ;

jumpStatement
    :   'continue' ';'            
    |   'break' ';'
    |   'return' expression? ';'
    ;

//------ Declaration
nonArrayTypeSpecifier
    :   type='int'
    |   type='bool'
    |   type='string'
    |   type='void'
    |   type=Identifier
    ;

typeSpecifier
    :   nonArrayTypeSpecifier (lbr)*
    ;

lbr
    :   '[' ']'
    ;

variableDeclaration
    :   typeSpecifier variableInitDeclarator (',' variableInitDeclarator)* ';'
    ;

variableInitDeclarator
    :   Identifier ('=' expression)?
    ;

classDeclaration
    :   'class' Identifier '{' memberDeclaration*'}'
    ;

memberDeclaration
    :   variableDeclaration
    |   functionDeclaration
    |   classConstructor
    ;
classConstructor
    :   Identifier '(' ')' blockStatement
    ;

functionDeclaration
    :   typeSpecifier Identifier '(' parameterDeclarationList? ')' blockStatement
    ;

parameterDeclarationList
    :   parameterDeclaration (',' parameterDeclaration)*
    ;

parameterDeclaration
    :   typeSpecifier Identifier
    ;

//------ Expression: http://en.cppreference.com/w/cpp/language/operator_precedence
expression
    :   expression op=('++' | '--')                  # PostfixIncDec    // Precedence 1
    |   expression '(' parameterList? ')'            # FunctionCall
    |   expression '[' expression ']'                # Subscript
    |   expression '.' Identifier                    # MemberAccess

    |   <assoc=right> op=('++'|'--') expression      # UnaryExpr        // Precedence 2
    |   <assoc=right> op=('+' | '-') expression      # UnaryExpr
    |   <assoc=right> op=('!' | '~') expression      # UnaryExpr
    |   <assoc=right> 'new' creator                  # New

    |   expression op=('*' | '/' | '%') expression   # BinaryExpr       // Precedence 3
    |   expression op=('+' | '-') expression         # BinaryExpr       // Precedence 4
    |   expression op=('<<'|'>>') expression         # BinaryExpr       // Precedence 5
    |   expression op=('<' | '>') expression         # BinaryExpr       // Precedence 6
    |   expression op=('<='|'>=') expression         # BinaryExpr
    |   expression op=('=='|'!=') expression         # BinaryExpr       // Precedence 7
    |   expression op='&' expression                 # BinaryExpr       // Precedence 8
    |   expression op='^' expression                 # BinaryExpr       // Precedence 9
    |   expression op='|' expression                 # BinaryExpr       // Precedence 10
    |   expression op='&&' expression                # BinaryExpr       // Precedence 11
    |   expression op='||' expression                # BinaryExpr       // Precedence 12

    |   <assoc=right> expression op='=' expression   # BinaryExpr       // Precedence 14

    |   Identifier                                   # Identifier
    |   constant                                     # Literal
    |   '(' expression ')'                           # SubExpression
    ;

creator
    :   nonArrayTypeSpecifier ('[' expression ']')+ ('[' ']')+ ('[' expression ']')+   # creatorError
    |   nonArrayTypeSpecifier ('[' expression ']')+ ('[' ']')*                         # creatorArray
    |   nonArrayTypeSpecifier                                                          # creatorNonArray
    ;

parameterList
    :   expression (',' expression)*
    ;

constant
    :   type=IntegerConstant
    |   type=CharacterConstant
    |   type=StringLiteral
    |   type=NullLiteral
    |   type=BoolConstant
    ;

//------ Reserved Keywords
Bool : 'bool';
Int : 'int';
Void : 'void';
String : 'string';

fragment Null : 'null';
fragment True : 'true';
fragment False : 'false';

If : 'if';
For : 'for';
While : 'while';
Break : 'break';
Continue : 'continue';
Return : 'return';
New : 'new';
Class : 'class';
This : 'this';

//------ Symbol
Plus : '+';
Minus : '-';
Star : '*';
Div : '/';
Mod : '%';

Less : '<';
Greater : '>';
Equal : '==';
NotEqual : '!=';
GreaterEqual : '>=';
LessEqual : '<=';

AndAnd : '&&';
OrOr : '||';
Not : '!';

LeftShift : '<<';
RightShift : '>>';
Tilde : '~';
Or : '|';
Caret : '^';
And : '&';

Assign : '=';

PlusPlus : '++';
MinusMinus : '--';

Dot : '.';
LBracket : '[';
RBracket : ']';

LParen : '(';
RParen : ')';

LBrace : '{';
RBrace : '}';

Question : '?';
Colon : ':';
Semi : ';';
Comma : ',';







//------ Constant
NullLiteral
    :   'null'
    ;

BoolConstant
    :   'true'
    |   'false'
    ;

IntegerConstant
    :   NonzeroDigit Digit*
    |   '0'
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

CharacterConstant
    :   '\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
        |   EscapeSequence
    ;
fragment
EscapeSequence
    :   SimpleEscapeSequence
    ;
fragment
SimpleEscapeSequence
    :   '\\' ['"?abfnrtv\\]
    ;
StringLiteral
    :   '"' SCharSequence? '"'
    ;
fragment
SCharSequence
    :   SChar+
    ;
fragment
SChar
    :   ~["\\\r\n]
    |   EscapeSequence
    ;

//------ Identifier
Identifier
    :   IdentifierNondigit ( IdentifierNondigit | Digit )*
    ;

fragment
IdentifierNondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

//------ Ignore
Whitespace
    :   [ \t]+ -> skip
    ;

Newline
    :   '\r'? '\n' -> skip
    ;

LineComment
    :   '//' ~[\r\n]* -> skip
    ;
