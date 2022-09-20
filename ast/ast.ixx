//This file was generated by ast_builder.exe v1.0.0
export module ast;

import <any>;
import <memory>;
import <vector>;

import core;

export namespace ast
{

namespace expr 
{

struct Assign   ;
struct Binary   ;
struct Grouping ;
struct Literal  ;
struct Unary    ;
struct Variable ;

struct VisitorExpr
{
	virtual ~VisitorExpr() = default;
	virtual std::any Visit(const Assign   & val) = 0;
	virtual std::any Visit(const Binary   & val) = 0;
	virtual std::any Visit(const Grouping & val) = 0;
	virtual std::any Visit(const Literal  & val) = 0;
	virtual std::any Visit(const Unary    & val) = 0;
	virtual std::any Visit(const Variable & val) = 0;
};
struct Expr
{
	virtual ~Expr() = default;
	virtual std::any Accept(VisitorExpr& visitor) const = 0;
};

using ExprPtr = std::unique_ptr<Expr>; 

struct Assign    : Expr
{
	Token name;
	std::unique_ptr<Expr> value;
	explicit Assign   (Token name_, std::unique_ptr<Expr> value_)
		: name(std::move(name_))
		, value(std::move(value_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Binary    : Expr
{
	std::unique_ptr<Expr> left;
	Token op;
	std::unique_ptr<Expr> right;
	explicit Binary   (std::unique_ptr<Expr> left_, Token op_, std::unique_ptr<Expr> right_)
		: left(std::move(left_))
		, op(std::move(op_))
		, right(std::move(right_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Grouping  : Expr
{
	std::unique_ptr<Expr> expression;
	explicit Grouping (std::unique_ptr<Expr> expression_)
		: expression(std::move(expression_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Literal   : Expr
{
	LiteralT value;
	explicit Literal  (LiteralT value_)
		: value(std::move(value_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Unary     : Expr
{
	Token op;
	std::unique_ptr<Expr> right;
	explicit Unary    (Token op_, std::unique_ptr<Expr> right_)
		: op(std::move(op_))
		, right(std::move(right_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Variable  : Expr
{
	Token name;
	explicit Variable (Token name_)
		: name(std::move(name_))
		{}
	std::any Accept(VisitorExpr& visitor) const override
	{
		return visitor.Visit(*this);
	}
};

} //namespace expr

namespace stmt 
{

struct Block      ;
struct Expression ;
struct Print      ;
struct Var        ;

struct VisitorStmt
{
	virtual ~VisitorStmt() = default;
	virtual std::any Visit(const Block      & val) = 0;
	virtual std::any Visit(const Expression & val) = 0;
	virtual std::any Visit(const Print      & val) = 0;
	virtual std::any Visit(const Var        & val) = 0;
};
struct Stmt
{
	virtual ~Stmt() = default;
	virtual std::any Accept(VisitorStmt& visitor) const = 0;
};

using StmtPtr = std::unique_ptr<Stmt>; 

struct Block       : Stmt
{
	std::vector<StmtPtr> statements;
	explicit Block      (std::vector<StmtPtr> statements_)
		: statements(std::move(statements_))
		{}
	std::any Accept(VisitorStmt& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Expression  : Stmt
{
	std::unique_ptr<expr::Expr> expression;
	explicit Expression (std::unique_ptr<expr::Expr> expression_)
		: expression(std::move(expression_))
		{}
	std::any Accept(VisitorStmt& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Print       : Stmt
{
	std::unique_ptr<expr::Expr> expression;
	explicit Print      (std::unique_ptr<expr::Expr> expression_)
		: expression(std::move(expression_))
		{}
	std::any Accept(VisitorStmt& visitor) const override
	{
		return visitor.Visit(*this);
	}
};
struct Var         : Stmt
{
	Token name;
	std::unique_ptr<expr::Expr> initializer;
	explicit Var        (Token name_, std::unique_ptr<expr::Expr> initializer_)
		: name(std::move(name_))
		, initializer(std::move(initializer_))
		{}
	std::any Accept(VisitorStmt& visitor) const override
	{
		return visitor.Visit(*this);
	}
};

} //namespace stmt
}//namespace ast
