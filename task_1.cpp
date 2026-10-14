#include<iostream>
using namespace std;

int main()
{
string name,degree,semester;
int age;
float cgpa;

cout<<"enter your name : ";
getline(cin,name);
cout<<"enter your age : ";
cin>>age;
cout<<"enter your cgpa : ";
cin>>cgpa;
cout<<"enter your semester : ";
cin>>semester;
cout<<"enter your degree : ";
cin>>degree;
cout<<endl;

cout<<"-----your information-----"<<endl;
cout<<"your name is : "<<name<<endl;
cout<<"your age is : "<<age<<endl;
cout<<"your cgpa is : "<<cgpa<<endl;
cout<<"your semester is : "<<semester<<endl;
cout<<"your degree is : "<<degree<<endl;
return 0;

}
