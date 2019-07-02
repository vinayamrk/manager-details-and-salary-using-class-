#include <iostream>

using namespace std;
class Manager
{
private:
    static int count;
protected:
    char name[20];
    float basic_sal,gross_sal;
public:
    Manager()
    {
        count++;
    }
    virtual void read_data()=0;
    virtual void compute_salary()=0;
    virtual void display_salary()=0;
    static void dis_count()
    {
        cout<<"Total of manager is"<<count<<endl;
    }
};
int Manager :: count=0;
class Pro_manager:public Manager
{
public:
    void read_data()
    {
        cout<<"Enter name of the of production Manager:";
        cin>>name;
        cout<<"Enter basic salary:";
        cin>>basic_sal;
    }
    void compute_salary()
    {
        float HRA,DA,allowance;
        HRA=basic_sal*0.1;
        DA=basic_sal*0.75;
        allowance=basic_sal*0.60;
        gross_sal=basic_sal+HRA+DA+allowance;
    }
    void display_salary()
    {
       cout<<"Gross salary is"<<gross_sal<<endl;
    }
};
class sal_manager:public Manager
{
public:
    void read_data()
    {
        cout<<"Enter name of the of sales Manager:";
        cin>>name;
        cout<<"Enter basic salary:";
        cin>>basic_sal;
    }
    void compute_salary()
    {
        float HRA,DA,allowance,TA;
        HRA=basic_sal*0.1;
        DA=basic_sal*0.75;
        TA=basic_sal*0.80;
        allowance=basic_sal*0.20;
        gross_sal=basic_sal+HRA+DA+allowance+TA;
    }
    void display_salary()
    {
       cout<<"Gross salary is"<<gross_sal<<endl;
    }
};
int main()
{
    Pro_manager p1,p2;
    sal_manager s1,s2;
    Manager *mgr;

    mgr=&p1;
    mgr->read_data();
    mgr->compute_salary();
    mgr->display_salary();



    mgr=&s1;
    mgr->read_data();
    mgr->compute_salary();
    mgr->display_salary();



    Manager::dis_count();

    return 0;
}

