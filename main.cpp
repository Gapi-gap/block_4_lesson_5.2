#include<iostream>
#include<string>

class Figure
{
public:
	Figure(int a)
		: a_(a)
	{ }
	virtual std::string Sides()
	{
		return "Стороны: a = " + std::to_string(a_);
	}

	virtual std::string Angles()
	{
		return "0";
	}

private:
	int a_;
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(0)
	{
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	std::string Sides() override
	{
		return "Стороны: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + ", d = " + std::to_string(d);
	}
	std::string Angles()override
	{
		return "Углы: a = " + std::to_string(A) + ", b = " + std::to_string(B) + ", c = " + std::to_string(C) + ", d = " + std::to_string(D);
	}


protected:
	//Стороны
	int a, b, c, d;
	//Углы
	int A, B, C, D;
};

class Parallelogram :public Quadrilateral
{
public:
	Parallelogram(int length, int width, int A, int B) :Quadrilateral(length, width, length, width, A, B, A, B)
	{
	}
};

class Rectangle :public Parallelogram
{
public:
	Rectangle(int length, int width) :Parallelogram(length, width, 90, 90)
	{
	}
};


class Rhombus :public Parallelogram
{
public:
	Rhombus(int length, int A, int B) :Parallelogram(length, length, A, B)
	{
	}
};

class Square :public Rectangle
{
public:
	Square(int length) :Rectangle(length, length)
	{
	}
};

class Triangles : public Figure
{
public:
	Triangles(int a, int b, int c, int A, int B, int C) : Figure(0)
	{
		a_ = (a);
		b_ = (b);
		c_ = (c);
		A_ = (A);
		B_ = (B);
		C_ = (C);
	}

	std::string Sides()override
	{
		return "Стороны: a = " + std::to_string(a_) + ", b = " + std::to_string(b_) + ", c = " + std::to_string(c_);
	}
	std::string Angles()override
	{
		return "Углы: a = " + std::to_string(A_) + ", b = " + std::to_string(B_) + ", c = " + std::to_string(C_);
	}

private:
	int a_, b_, c_;
	int A_, B_, C_;
};

class RightTriangle : public Triangles
{
public:
	RightTriangle(int a, int b, int c, int A, int B) :Triangles(a, b, c, A, B, 90)
	{
	}
};

class IsoscelesTriangle : public Triangles
{
public:
	IsoscelesTriangle(int a, int b, int A, int B) :Triangles(a, b, a, A, B, A)
	{
	}
};

class EquilateralTriangle : public Triangles
{
public:
	EquilateralTriangle(int a) :Triangles(a, a, a, 60, 60, 60)
	{
	}
};


void print_info(Figure* figura);

int main()
{
	setlocale(LC_ALL, "ru");
	//PrintInfo();
	Figure* figura = new Figure(0);
	print_info(figura);
	delete figura;
	return EXIT_SUCCESS;
}

void print_info(Figure* ptr)
{
	std::cout << "Треугольник:" << std::endl;
	Triangles triagle(10, 20, 30, 50, 60, 70);
	ptr = &triagle;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;


	std::cout << "Прямоугольный треугольник:" << std::endl;
	RightTriangle rightTriangle(10, 20, 45, 45, 45);
	ptr = &rightTriangle;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;

	std::cout << "Равнобедренный треугольник:" << std::endl;
	IsoscelesTriangle isoscelesTriangle(10, 20, 55, 70);
	ptr = &isoscelesTriangle;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;

	EquilateralTriangle equilateralTriangle(30);
	std::cout << "Равносторонний треугольник:" << std::endl;
	ptr = &equilateralTriangle;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;


	//базовый
	Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
	ptr = &quadrilateral;
	std::cout << "Четырехугольник:" << std::endl;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;
	//Прямоугольник

	Rectangle rectangle(10, 20);
	ptr = &rectangle;
	std::cout << "Прямоугольник:" << std::endl;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;
	//Квадрат
	Square square(10);
	ptr = &square;
	std::cout << "Квадрат:" << std::endl;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;
	//Параллелограмм
	Parallelogram parallelogram(20, 30, 30, 40);
	ptr = &parallelogram;
	std::cout << "Параллелограмм:" << std::endl;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;
	//Ромб
	Rhombus rhombus(30, 30, 40);
	ptr = &rhombus;
	std::cout << "Ромб:" << std::endl;
	std::cout << ptr->Sides() << std::endl;
	std::cout << ptr->Angles() << std::endl;
	std::cout << std::endl;
}