#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Car {
protected: string model;
public:    Car(const string& model) : model(model) {}
      virtual ~Car() {
    cout << endl;
}
};

class Mercedes : public Car {
public: Mercedes(const string& model) : Car(model) {}
      ~Mercedes() {
          cout << "Brand: Mercedes, model: " << model << endl;
      }
};
class Lada : public Car {
public: Lada(const string& model) : Car(model) {}
      ~Lada() {
          cout << "Brand: Lada, model: " << model << endl;
      }
};
class Porsche : public Car {
public: Porsche(const string& model) : Car(model) {}
      ~Porsche() {
          cout << "Brand: Porsche, model: " << model << endl;
      }
};
class BMW : public Car {
public: BMW(const string& model) : Car(model) {}
      ~BMW() {
          cout << "Brand: BMW, model: " << model << endl;
      }
};
void loadfile(const string& filename, vector<Car*>& cars) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file2222: " << filename << endl;
        return;
    }
    string brand, model;
    while (file >> brand >> model) {
        if (brand == "Mercedes") {
            cars.push_back(new Mercedes(model));
        }
        else if (brand == "Lada") {
            cars.push_back(new Lada(model));
        }
        else if (brand == "BMW") {
            cars.push_back(new BMW(model));
        }
        else if (brand == "Porsche") {
            cars.push_back(new Porsche(model));
        }
    }
    file.close();
}
int main() {
    vector<Car*> cars;
    loadfile("cars.txt", cars);
    for (Car* car : cars) {
        delete car;
    }
}