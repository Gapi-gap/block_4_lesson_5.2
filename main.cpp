#include<iostream>
#include<string>

class Quadrilateral
{
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
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
	std::string Sides()
	{
		return "Стороны: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + ", d = " + std::to_string(d);
	}
	std::string Angles()
	{
		return "Углы: a = " + std::to_string(A) + ", b = " + std::to_string(B) + ", c = " + std::to_string(C) + ", d = " + std::to_string(D);
	}


private:
	//Стороны
	int a, b, c, d;
	//Углы
	int A, B, C, D;
};

class Parallelogram :public Quadrilateral
{
public:
	Parallelogram(int length, int width,int A,int B):Quadrilateral(length, width, length, width,A,B,A,B)
	{ }
};

class Rectangle :public Parallelogram
{
public:
	Rectangle(int length, int width) :Parallelogram(length, width, 90, 90)
	{}
};


class Rhombus :public Parallelogram
{
public:
	Rhombus(int length, int A, int B):Parallelogram(length, length,A,B)
	{ }
};

class Square :public Rectangle
{
public:
	Square(int length):Rectangle(length, length)
	{}
};

class Triangles
{
public:
	Triangles(int a,int b,int c,int A,int B,int C)
		: a_(a),
		b_(b),
		c_(c),
		A_(A),
		B_(B),
		C_(C)
	{}

	std::string Sides()
	{
		return "Стороны: a = " + std::to_string(a_) + ", b = " + std::to_string(b_) + ", c = " + std::to_string(c_);
	}
	std::string Angles()
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
	RightTriangle(int a,int b,int c,int A,int B):Triangles(a,b,c,A,B,90)
	{ }
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


void PrintInfo()
{
	//четурехугольники
	{
		//базовый
		Quadrilateral quadrilateral(10,20,30,40,50,60,70,80);
		std::cout << "Четырехугольник:" << std::endl;
		std::cout<<quadrilateral.Sides()<<std::endl;
		std::cout << quadrilateral.Angles() << std::endl;
		std::cout << std::endl;
		//Прямоугольник
		Rectangle rectangle(10,20);
		std::cout << "Прямоугольник:" << std::endl;
		std::cout << rectangle.Sides() << std::endl;
		std::cout << rectangle.Angles() << std::endl;
		std::cout << std::endl;
		//Квадрат
		Square square(10);
		std::cout << "Квадрат:" << std::endl;
		std::cout << square.Sides() << std::endl;
		std::cout << square.Angles() << std::endl;
		std::cout << std::endl;
		//Параллелограмм
		Parallelogram parallelogram(20,30,30,40);
		std::cout << "Параллелограмм:" << std::endl;
		std::cout << parallelogram.Sides() << std::endl;
		std::cout << parallelogram.Angles() << std::endl;
		std::cout << std::endl;
		//Ромб
		Rhombus rhombus(30,30,40);
		std::cout << "Ромб:" << std::endl;
		std::cout << rhombus.Sides() << std::endl;
		std::cout << rhombus.Angles() << std::endl;
		std::cout << std::endl;
	}

	//треугольник
	{
		Triangles triangles(10, 20, 30, 50, 60, 70);
		std::cout << "Треугольник:" << std::endl;
		std::cout << triangles.Sides() << std::endl;
		std::cout << triangles.Angles() << std::endl;
		std::cout << std::endl;

		RightTriangle right_triangle(10, 20, 30, 50, 60);
		std::cout << "Прямоугольный треугольник:" << std::endl;
		std::cout << right_triangle.Sides() << std::endl;
		std::cout << right_triangle.Angles() << std::endl;
		std::cout << std::endl;

		IsoscelesTriangle isosceles_triangle(10, 20, 60, 70);
		std::cout << "Равнобедренный треугольник:" << std::endl;
		std::cout << isosceles_triangle.Sides() << std::endl;
		std::cout << isosceles_triangle.Angles() << std::endl;
		std::cout << std::endl;

		EquilateralTriangle equilateralTriangle(30);
		std::cout << "Равносторонний треугольник:" << std::endl;
		std::cout << equilateralTriangle.Sides() << std::endl;
		std::cout << equilateralTriangle.Angles() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	PrintInfo();
}