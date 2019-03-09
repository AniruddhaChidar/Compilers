#include <stdlib.h>
template class Number_Ast<double>;
template class Number_Ast<int>;
int Ast::labelCounter;

///////////////////////////////////////////////////////////////////
Ast::Ast()
{
}

Ast::~Ast()
{
}

Data_Type Ast::get_data_type()
{
	return node_data_type;
}

void Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Ast::is_value_zero()
{
	return true;
}

bool Ast::check_ast()
{
	return true;
}

Symbol_Table_Entry &Ast::get_symbol_entry()
{
	Symbol_Table_Entry &s = *static_cast<Symbol_Table_Entry *>(NULL);
	return s;
}

// void Ast::print(ostream & file_buffer){
// 	file_buffer<<"\n";
// }

///////////////////////////////////////////////////////////////////
Assignment_Ast::Assignment_Ast(Ast *temp_lhs, Ast *temp_rhs, int line)
{
	lhs = temp_lhs;
	rhs = temp_rhs;
	lineno = line;
}

Assignment_Ast::~Assignment_Ast()
{
	free(lhs);
	free(rhs);
}

bool Assignment_Ast::check_ast()
{
	return ((lhs->get_data_type() == rhs->get_data_type()) && lhs->check_ast() && rhs->check_ast());
}

void Assignment_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_SPACE << "Asgn:\n";
	file_buffer << AST_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n"
				<< AST_NODE_SPACE << "RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
}

///////////////////////////////////////////////////////////////////
Name_Ast::Name_Ast(string &name, Symbol_Table_Entry &var_entry, int line)
{
	variable_symbol_entry = &var_entry;
	lineno = line;
	set_data_type(var_entry.get_data_type());
	// SEE LATER for name NOT NEEDED
}

Name_Ast::~Name_Ast()
{
	// free(variable_symbol_entry);
}

Data_Type Name_Ast::get_data_type()
{
	return node_data_type;
}

Symbol_Table_Entry &Name_Ast::get_symbol_entry()
{
	return *variable_symbol_entry;
}

void Name_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

void Name_Ast::print(ostream &file_buffer)
{
	file_buffer << "Name : " << variable_symbol_entry->get_variable_name();
}

///////////////////////////////////////////////////////////////////
template <class T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
}

template <class T>
Number_Ast<T>::~Number_Ast()
{
}

template <class T>
Data_Type Number_Ast<T>::get_data_type()
{
	return node_data_type;
}

template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

template <class T>
bool Number_Ast<T>::is_value_zero()
{
	if (constant == 0)
		return true;
	else
		return false;
}

template <class T>
void Number_Ast<T>::print(ostream &file_buffer)
{
	file_buffer << "Num : " << constant;
}

// ///////////////////////////////////////////////////////////////////

Data_Type Arithmetic_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Arithmetic_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast()
{
	if (rhs == NULL)
		return lhs->check_ast();
	return ((lhs->get_data_type() == rhs->get_data_type()) && lhs->check_ast() && rhs->check_ast());
}

void Arithmetic_Expr_Ast::print(ostream &file_buffer)
{
}

// ///////////////////////////////////////////////////////////////////
Plus_Ast::Plus_Ast(Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
}

void Plus_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_NODE_SPACE << "Arith: PLUS\n";
	file_buffer << AST_SUB_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n";
	file_buffer << AST_SUB_NODE_SPACE << "RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
}

// ///////////////////////////////////////////////////////////////////
Minus_Ast::Minus_Ast(Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
}

void Minus_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_NODE_SPACE << "Arith: MINUS\n";
	file_buffer << AST_SUB_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n";
	file_buffer << AST_SUB_NODE_SPACE << "RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
}

// ///////////////////////////////////////////////////////////////////
Mult_Ast::Mult_Ast(Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
}

void Mult_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_NODE_SPACE << "Arith: MULT\n";
	file_buffer << AST_SUB_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n";
	file_buffer << AST_SUB_NODE_SPACE << "RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
}

// ///////////////////////////////////////////////////////////////////
Divide_Ast::Divide_Ast(Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
}

void Divide_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_NODE_SPACE << "Arith: DIV\n";
	file_buffer << AST_SUB_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")\n";
	file_buffer << AST_SUB_NODE_SPACE << "RHS (";
	rhs->print(file_buffer);
	file_buffer << ")";
}

// ///////////////////////////////////////////////////////////////////
UMinus_Ast::UMinus_Ast(Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
}

void UMinus_Ast::print(ostream &file_buffer)
{
	file_buffer << "\n"
				<< AST_NODE_SPACE << "Arith: UMINUS\n";
	file_buffer << AST_SUB_NODE_SPACE << "LHS (";
	lhs->print(file_buffer);
	file_buffer << ")";
}
// ///////////////////////////////////////////////////////////////////

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast *cond, Ast *l, Ast *r, int line)
{
	lineno = line;
	lhs = l;
	rhs = r;
	this->cond = cond;
}

Conditional_Expression_Ast::~Conditional_Expression_Ast()
{
}

void Conditional_Expression_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Cond:\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"IF_ELSE";
	cond->print(file_buffer);
	file_buffer<<"\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

// ///////////////////////////////////////////////////////////////////

Return_Ast::Return_Ast(int line)
{
	lineno = line;
}

Return_Ast::~Return_Ast()
{
}
void Return_Ast::print(ostream &file_buffer)
{
}

// ///////////////////////////////////////////////////////////////////

Relational_Expr_Ast::Relational_Expr_Ast(Ast *lhs, Relational_Op rop, Ast *rhs, int line)
{
	lineno = line;
	lhs_condition = lhs;
	rhs_condition = rhs;
	rel_op = rop;
}

Relational_Expr_Ast::~Relational_Expr_Ast()
{
}

Data_Type Relational_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Relational_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Relational_Expr_Ast::check_ast()
{
	return ((lhs_condition->get_data_type() == rhs_condition->get_data_type()) && (lhs_condition->check_ast() && rhs_condition->check_ast()));
}

string Relop_array[] = {"LE", "LT", "GT", "GE", "EQ", "NE"};

void Relational_Expr_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: "<<Relop_array[rel_op]<<"\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_condition->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_condition->print(file_buffer);
	file_buffer<<")";
}

// ///////////////////////////////////////////////////////////////////

Logical_Expr_Ast::Logical_Expr_Ast(Ast *lhs, Logical_Op bop, Ast *rhs, int line)
{
	lineno = line;
	lhs_op = lhs;
	rhs_op = rhs;
	bool_op = bop;
}

Logical_Expr_Ast::~Logical_Expr_Ast()
{
}

Data_Type Logical_Expr_Ast::get_data_type()
{
	return node_data_type;
}

void Logical_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Logical_Expr_Ast::check_ast()
{
	if (rhs_op == NULL)
		return lhs_op->check_ast();
	return ((lhs_op->get_data_type() == rhs_op->get_data_type()) && (lhs_op->check_ast() && rhs_op->check_ast()));
}

string logicOp_array[] = {"NOT", "OR", "AND"};

void Logical_Expr_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: "<<logicOp_array[bool_op]<<"\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_op->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_op->print(file_buffer);
	file_buffer<<")";
}

// ///////////////////////////////////////////////////////////////////

Selection_Statement_Ast::Selection_Statement_Ast(Ast *cond, Ast *then_part, Ast *else_part, int line)
{
	lineno = line;
	this->cond = cond;
	this->then_part = then_part;
	this->else_part = else_part;
}

Selection_Statement_Ast::~Selection_Statement_Ast()
{
}

Data_Type Selection_Statement_Ast::get_data_type()
{
	return node_data_type;
}

void Selection_Statement_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Selection_Statement_Ast::check_ast()
{
	if (else_part == NULL)
		return cond->check_ast() && then_part->check_ast();
	else
		return cond->check_ast() && (then_part->check_ast() && else_part->check_ast());
}

void Selection_Statement_Ast::print(ostream &file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"IF : \n"<<AST_SPACE<<"CONDITION (";
	cond->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_SPACE<<"THEN (";
	then_part->print(file_buffer);
	file_buffer<<")";
	if(else_part!=NULL){
		file_buffer<<AST_SPACE<<"\n"<<AST_SPACE<<"ELSE (";
		else_part->print(file_buffer);
		file_buffer<<")";
	}
}

// ///////////////////////////////////////////////////////////////////

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast *cond, Ast *body, int line, bool do_form)
{
	lineno = line;
	this->cond = cond;
	this->body = body;
	is_do_form = do_form;
}

Iteration_Statement_Ast::~Iteration_Statement_Ast()
{
}

Data_Type Iteration_Statement_Ast::get_data_type()
{
	return node_data_type;
}

void Iteration_Statement_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Iteration_Statement_Ast::check_ast()
{
	return cond->check_ast() && body->check_ast();
}

void Iteration_Statement_Ast::print(ostream &file_buffer)
{
	if(is_do_form){
		file_buffer<<"\n"<<AST_SPACE<<"DO (";
		body->print(file_buffer);
		file_buffer<<")\n";
		file_buffer<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
	}
	else{
		file_buffer<<"\n"<<AST_SPACE<<"WHILE : \n"<<AST_SPACE<<"CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")\n";
		file_buffer<<AST_SPACE<<"BODY (";
		body->print(file_buffer);
		file_buffer<<")";
	}
	
}

// ///////////////////////////////////////////////////////////////////

Sequence_Ast::Sequence_Ast(int line)
{
	lineno = line;
}

Sequence_Ast::~Sequence_Ast()
{
}

void Sequence_Ast::ast_push_back(Ast *ast)
{
	statement_list.push_back(ast);
}

void Sequence_Ast::print(ostream &file_buffer)
{
	list<Ast *>::iterator it;
    for (it = statement_list.begin(); it != statement_list.end(); ++it)
    {
		file_buffer<<"\n";
        (*it)->print(file_buffer);
    }
}