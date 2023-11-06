#include <string>

using namespace std;

// header file of personType:
class personType {
public:
    void print() const;
    void setName(string, string);
    string getFirstName() const;
    string getLastName() const;
    personType(string = "", string = "");

private:
    string firstName;
    string lastName;
};