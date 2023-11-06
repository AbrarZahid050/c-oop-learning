// dateType header file:

class dateType {
public:
    void setDate(int, int, int);
    int getDay() const;
    void printDate() const;
    dateType(int = 1, int = 1, int = 1900);

private:
    int dMonth;
    int dDay;
    int dYear;
};