/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    FLOAT = 259,
    VOID = 260,
    NAME = 261,
    IF = 262,
    ELSE = 263,
    DO = 264,
    WHILE = 265,
    AND = 266,
    OR = 267,
    NOT = 268,
<<<<<<< HEAD
    FOR = 269,
    DOUBLE_NUMBER = 270,
    INTEGER_NUMBER = 271,
    RELOP = 272,
    EQOP = 273
=======
    DOUBLE_NUMBER = 269,
    INTEGER_NUMBER = 270,
    RELOP = 271,
    EQOP = 272
>>>>>>> accb7be84200cf8ea2a969a8278ae26de9ce04e8
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	Relational_Op relop_value; 
	Sequence_Ast * seq_ast;

<<<<<<< HEAD
#line 87 "parser.tab.h" /* yacc.c:1909  */
=======
#line 86 "parser.tab.h" /* yacc.c:1909  */
>>>>>>> accb7be84200cf8ea2a969a8278ae26de9ce04e8
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
