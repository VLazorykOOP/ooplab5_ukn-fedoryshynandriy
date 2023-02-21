using namespace std;
#include <string>
#include <vector>
#include <iostream>
//TASK 1
//Створити клас Pair(пара чисел);
//визначити методи зміни полів і ви - числения твори чисел.
//Визначити похідний клас Rectangle(прямокутник) з полями - сторонами.
//Визначити методи обчислення периметра і площі прямокутника.

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
    cout << "TASK 1: \n"<<endl;
    Rectangle pair1(3, 10);
    cout << pair1.Perimeter();
    cout << pair1.Area();
    cout << endl;
    return 0;
}



//TASK2
//Використовуючи ієрархію й композицію класів, створити бінарне дерево.
//У бінарного дерева є кореневий вузол.
//Ми можемо вставляти вузол.Ми можемо обходити завширшки.
struct Node 
{
    int number;
    Node* left;
    Node* right;

    Node(int number) 
    {
        this->number = number;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree 
{
 public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void addNode(int number) {
        Node* nextNode = new Node(number);

        if (root == nullptr) {
            root = nextNode;
        }
        else {
            Node* currentNode = root;
            Node* parent;

            while (true) {
                parent = currentNode;

                if (number < currentNode->number) {
                    currentNode = currentNode->left;
                    if (currentNode == nullptr) {
                        parent->left = nextNode;
                        return;
                    }
                }
                else {
                    currentNode = currentNode->right;
                    if (currentNode == nullptr) {
                        parent->right = nextNode;
                        return;
                    }
                }
            }
        }
    }

    void Traversal(Node* currentNode) {
        if (currentNode != nullptr) {
            cout << currentNode->number;
            cout << " ";
            Traversal(currentNode->left);
            Traversal(currentNode->right);
        }
    }
};

int Task2() {
    cout << "TASK 2 \n";
    BinaryTree numerical;
    int n = 0;;
    cout << "\nInput number of Nodes you want to add:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number = 0;
        cout << "Input node[" << i << "] : ";
        cin >> number;
        numerical.addNode(number);
    }
    cout << "\nBinary tree: \n";
    numerical.Traversal(numerical.root);

    return 0;
}



//TASK 3
//Створити ієрархію класів крапка й кольорова крапка.
//Перевизначити вивід у потік і введення з потоку, конструктор копіювання,
//оператор присвоювання через відповідні функції базового класу.

class Coordinates {
public:
	Coordinates() {
		x = 0;
		y = 0;
	};

	Coordinates(int _x, int _y) {
		x = _x;
		y = _y;
	}
	Coordinates(Coordinates& count) {
		x = count.x;
		y = count.y;
	}
	~Coordinates() {};

	int x;
	int y;


	void print() {
		cout << "Coordinate X= " << x << endl;
		cout << "Coordinate Y= " << y << endl;
	}

	void print(ostream& p) {
		p << "Coordinate X= " << x << endl;
		p << "Coordinate Y= " << y << endl;
	}
};

class Dot {
public:
	Dot() {
		coordinates_count = 0;
	}

	Dot(int _coordinates_count) 
	{
		coordinates_count = _coordinates_count;
		coordinates = new Coordinates[coordinates_count];
	}

	Dot(Dot& count) 
	{
		coordinates_count = count.coordinates_count;
		coordinates = new Coordinates[count.coordinates_count];

		for (int coordinateNumber = 0; coordinateNumber < coordinates_count; coordinateNumber++)
		{
			coordinates[coordinateNumber] = count.coordinates[coordinateNumber];
		}
	}

	~Dot()
	{
		if (coordinates) 
		{
			delete[] coordinates;
		}
	}


	int dot_number;
	int coordinates_count;
	Coordinates* coordinates;



	void print() 
	{
		cout << "Dots number=  " << dot_number << endl;
	}


	void setDotNumber(int _dot_number) 
	{
		dot_number = _dot_number;
	}

	void setCoordinatesCount(int _coordinates_cout) 
	{
		coordinates_count = _coordinates_cout;
	}

	friend ostream& operator<<(ostream& p, Dot& dot)
	{
		p << "Dots number: " << dot.dot_number << endl;
		p << "Coordinates count= " << dot.coordinates_count << endl;

		cout << "Coordinates:\n";
		for (int coordinateNumber = 0; coordinateNumber < dot.coordinates_count; coordinateNumber++) 
		{
			cout <<endl<< "Coordinate number: " << coordinateNumber << endl;
			dot.coordinates[coordinateNumber].print(p);
		}
		return p;
	}

	void operator=(Dot& count) 
	{
		coordinates_count = count.coordinates_count;
		dot_number = count.dot_number;
		coordinates = new Coordinates[count.coordinates_count];

		for (int coordinateNumber = 0; coordinateNumber < coordinates_count; coordinateNumber++)
		{
			coordinates[coordinateNumber] = count.coordinates[coordinateNumber];
		}
	}

};


class ColourDot : public Dot {
public:
	ColourDot() : Dot() 
	{
		dot_number = 3;
	}

	ColourDot(ColourDot& count) : Dot() 
	{
		dot_number = 3;

		coordinates_count = count.coordinates_count;
		dot_number = count.dot_number;
		coordinates = new Coordinates[count.coordinates_count];

		for (int countNumber = 0; countNumber < coordinates_count; countNumber++) 
		{
			coordinates[countNumber] = count.coordinates[countNumber];
		}
	}

	ColourDot(int _coordinates_count) : Dot(_coordinates_count)
	{
		dot_number = 4;
	}

	void operator=(ColourDot& count) 
	{
		ColourDot();
		coordinates_count = count.coordinates_count;
		dot_number = count.dot_number;
		coordinates = new Coordinates[count.coordinates_count];

		for (int coordinateNumber = 0; coordinateNumber < coordinates_count; coordinateNumber++) 
		{
			coordinates[coordinateNumber] = count.coordinates[coordinateNumber];
		}
	}
};

int Task3() {
	ColourDot dot(4);

	dot.coordinates[0].x = int(5);
	dot.coordinates[0].y = int(5);

	dot.coordinates[1].x = int(6);
	dot.coordinates[1].y = int(6);

	dot.coordinates[2].x = int(7);
	dot.coordinates[2].y = int(7);

	dot.coordinates[3].x = int(8);
	dot.coordinates[3].y = int(8);

	cout << "Your dots: \n";
	cout << dot;
	

	return 0;
}

int main()
{
  std::cout << "                                                Lab 5"<<endl;
  cout << "-----------------------------------------------------------------------------------------------------" <<endl;
  cout << "Select task(1-3)\n";
  int chain;
  cin >> chain;
  if (chain == 1) chain = Task1();
  if (chain == 2) chain = Task2();
  if (chain == 3) chain = Task3();
}

