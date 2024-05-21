#include<iostream>
#include<vector>

using namespace std;

class person
{
public:
    person(){};
    ~person(){};
    void get_ID(int id)
    {
        this->ID = id;
        cout << "his id is " << id << endl;
    }
    void get_sex(int sex)
    {
        this->sex = sex;
        if (sex)
            cout << "he is male"<< endl;
        else
            cout << "she is female" << endl;
    }
    void get_num(long long int num)
    {
        
        this->creditNum = num;
        
        cout << "the creditnumber is " << num;
        cout << endl;
    }
    class date
    {
    public:
        date(int y, int m, int d):year(y), month(m), day(d){};
        ~date(){};
        void printDate()
        {
            cout << "his birthday is " << year << '.' << month << '.' << day;
        }
    private:
        int year,month,day;
    };
private:
    int ID;
    int sex;
    long long int creditNum;
};

int main()
{
    person p;
    int id;
    int sex;
    int y,m,d;
    long long int x;
    cout << "ID: ";
    cin >> id;
    cout << endl;
    cout << "sex: ";
    cin >> sex;
    cout <<endl;
    cout << "birthday: year/month/day";
    cin >> y >> m >> d;
    cout << endl;
    cout << "creditNum : ";
    cin >> x;
    p.get_ID(id);
    p.get_num(x);
    p.get_sex(sex);
    person::date date1(y, m ,d);
    date1.printDate();
    return 0;
}   