#include <iostream>
#include<string>

class shapes {

public:
    std::string name;
    int side_a = 0;
    int side_b = 0;
    int side_c = 0;
    int side_d = 0;

    int cornerA = 0;
    int cornerB = 0;
    int cornerC = 0;
    int cornerD = 0;


    shapes(int a, int b, int c, int cA, int cB, int cC) : side_a(a), side_b(b), side_c(c),
        cornerA(cA), cornerB(cB), cornerC(cC) {

        this->side_a = a;
        this->side_b = b;
        this->side_c = c;

        this->cornerA = cA;
        this->cornerB = cB;
        this->cornerC = cC;

    }
    virtual void print_info() {
        std::cout << name << std::endl << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c <<
            std::endl << "Углы: A=" << cornerA << " B=" << cornerB << " C=" << cornerC << std::endl << std::endl;
    }


    shapes(int a, int b, int c, int d, int cA, int cB, int cC, int cD) :side_a(a), side_b(b), side_c(c), side_d(d),
        cornerA(cA), cornerB(cB), cornerC(cC), cornerD(cD) {

        this->side_d = d;
        this->cornerD = cD;

    }

    virtual void print_info_two() {
        std::cout << name << std::endl << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d <<
            std::endl << "Углы: A=" << cornerA << " B=" << cornerB << " C=" << cornerC << " D=" << cornerD <<
            std::endl << std::endl;
    }

};




class triangle :public shapes {
public:

    triangle(int a, int b, int c, int cA, int cB, int cC) :shapes(a, b, c, cA, cB, cC) {
        try {
            if (cA + cB + cC != 180) {
                throw "Ошибка создания фигуры. Причина: сумма углов не равна 180";
            }
            name = "Треугольник:";
            print_info();

        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }

};
class rectangular_triangle :public shapes {
public:
    rectangular_triangle(int a, int b, int c, int cA, int cB, int cC) :shapes(a, b, c, cA, cB, cC) {

        try {
            if (cornerC != 90) {
                throw "Ошибка создания фигуры. Причина: угол С не равен 90 градусов";
            }
            name = "Прямоугольный треугольник:";
            print_info();
        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }
};


class isosceles_triangle : public shapes {
public:
    isosceles_triangle(int a, int b, int c, int cA, int cB, int cC) : shapes(a, b, c, cA, cB, cC) {
        try {
            if (side_a != side_c || cornerA != cornerC) {
                throw "Ошибка создания фигуры. Причина: стороны а и с не равны, или углы А и С не равны";
            }

            name = "Равнобедренный треугольник:";
            print_info();
        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }

};

class equilateral_triangle : public shapes {
public:
    equilateral_triangle(int a, int b, int c, int cA, int cB, int cC) : shapes(a, b, c, cA, cB, cC) {

        try {
            if (side_a != side_b || side_a != side_c || side_b != side_a || side_b != side_c || side_c != side_a || side_c != side_b || cornerA != 60 || cornerB != 60 || cornerC != 60) {
                throw "Ошибка создания фигуры. Причина: стороны не равны, или углы не равны 60 градусов";
            }


            name = "Равносторонний треугольник:";
            print_info();
        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }

};

class quadrangle : public shapes {
public:
    quadrangle(int a, int b, int c, int d, int cA, int cB, int cC, int cD) : shapes(a, b, c, d, cA, cB, cC, cD) {
        try {
            if (cA + cB + cC + cD != 360) {
                throw "Ошибка создания фигуры. Причина: сумма углов не равна 360";
            }
            name = "Четырехугольник:";
            print_info_two();

        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }
};

class rectangle : public shapes {
public:
    rectangle(int a, int b, int c, int d, int cA, int cB, int cC, int cD) : shapes(a, b, c, d, cA, cB, cC, cD) {

        try {
            if (side_a != side_c || side_c != side_a || side_b != side_d || side_d != side_b || cornerA != 90 || cornerB != 90 || cornerC != 90 || cornerD != 90) {
                throw "Ошибка создания фигуры. Причина: стороны а и с или b и d не равны, или углы не равны 90 градусов";
            }
            name = "Прямоугольник:";
            print_info_two();

        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }

};

class square : public shapes {
public:
    square(int a, int b, int c, int d, int cA, int cB, int cC, int cD) : shapes(a, b, c, d, cA, cB, cC, cD) {

        try {
            if (side_a != side_b || side_a != side_c || side_a != side_d || side_b != side_a || side_b != side_c || side_b != side_d ||
                side_c != side_a || side_c != side_b || side_c != side_d || side_d != side_a || side_d != side_b || side_d != side_c || cornerA != 90 || cornerB != 90 || cornerC != 90 || cornerD != 90) {
                throw "Ошибка создания фигуры. Причина: стороны не равны, или углы не равны 90 градусов";
            }

            name = "Квадрат:";
            print_info_two();
        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;
        }
    }

};

class parallelogram : public shapes {
public:
    parallelogram(int a, int b, int c, int d, int cA, int cB, int cC, int cD) : shapes(a, b, c, d, cA, cB, cC, cD) {
        try {
            if (side_a != side_c || side_c != side_a || side_b != side_d || side_d != side_b || cornerA != cornerC || cornerC != cornerA || cornerB != cornerD || cornerD != cornerB) {
                throw "Ошибка создания фигуры. Причина: стороны а и с или b и d не равны, или угол А не равен углу С, или угол B не равен углу D";
            }

            name = "Параллелограмм:";
            print_info_two();

        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;

        }
    }
};

class rhomb : public shapes {
public:
    rhomb(int a, int b, int c, int d, int cA, int cB, int cC, int cD) : shapes(a, b, c, d, cA, cB, cC, cD) {
        try {
            if (side_a != side_b || side_a != side_c || side_a != side_d || side_b != side_a || side_b != side_c || side_b != side_d ||
                side_c != side_a || side_c != side_b || side_c != side_d || side_d != side_a || side_d != side_b || side_d != side_c || cornerA != cornerC || cornerC != cornerA || cornerB != cornerD || cornerD != cornerB) {
                throw "Ошибка создания фигуры. Причина: стороны  не равны, или угол А не равен углу С, или угол B не равен углу D";
            }
            name = "Ромб:";
            print_info_two();
        }
        catch (const char* excapt) {
            std::cout << excapt << std::endl << std::endl;

        }
    }
};




int main()
{
    setlocale(LC_ALL, "ru");

    triangle tri(10, 20, 30, 50, 60, 70);


    rectangular_triangle rect(10, 20, 30, 50, 60, 90);


    isosceles_triangle isos(10, 20, 10, 50, 60, 50);


    equilateral_triangle equi(30, 30, 30, 60, 60, 60);


    quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);


    rectangle rectang(10, 20, 10, 20, 90, 90, 90, 90);


    square square(20, 20, 20, 20, 90, 90, 89, 90);


    parallelogram paral(20, 30, 20, 30, 30, 40, 30, 40);


    rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);


    return 0;
}