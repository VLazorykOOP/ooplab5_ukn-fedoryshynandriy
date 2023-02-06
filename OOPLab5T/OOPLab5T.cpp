using namespace std;
#include <string>
#include <vector>
#include <iostream>
class Pair
{
protected:
    int x, y;
public:
    Pair(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
    void SetXY(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
   
    int Product()
    {
        return x * y;
    }
};

class Rectangle : protected Pair
{
 public:
    Rectangle(int x1 = 1, int y1 = 1) : Pair(x1, y1)
    {
        if (x1 <= 0 || y1 <= 0) throw std::invalid_argument("arguments must be greater zero\n");
    }
    int Perimeter()
    {
        int perim = 0;
        perim = 2 * (x + y);
        cout << " Perimeter of rectangle  (a: " << x << ", b: " << y << ")  = ";
        return perim;
    }
    int Area()
    {   
        int area = 0;
        area = Product();
        cout <<endl<< "\n Area of rectangle  (a: " << x << ", b: " << y << ")  = ";
        return area;
    }
};


int Task1()
{
    cout << "Task 1: \n"<<endl;
    Rectangle pair1(3, 10);
    cout << pair1.Perimeter();
    cout << pair1.Area();
    cout << endl;
    return 0;
}

int main()
{
  std::cout << "                                                Lab 5"<<endl;
  cout << "-----------------------------------------------------------------------------------------------------" <<endl;
  int chain = 1;
  //int chain;
  //cin >> chain;

  if (chain == 1) chain = Task1();
  //if (chain == 2) chain = Task2();
  //if (chain == 3) chain = Task3();
}

