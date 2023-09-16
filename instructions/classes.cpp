#include <iostream>

class Person{
    std::string name;  // модификатор доступа не указан (private)
    unsigned age;   // модификатор доступа не указан (private)
public:
    Person(std::string p_name, unsigned p_age)
    {
        name = p_name;
        age = p_age;
        std::cout << "Person has been created" << std::endl;
    }
    Person(std::string p_name): Person(p_name, 18) // вызов первого конструктора
    {
        std::cout << "Second constructor" << std::endl;
    }
    Person(): Person(std::string("Undefined")) // вызов второго конструктора
    {
        std::cout << "Third constructor" << std::endl;
    }
    void print(){
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
    void setAge(unsigned p_age){
        if (p_age > 0 && p_age < 110)
            age = p_age;
    }
    std::string getName(){
        return name;
    }
    unsigned getAge(){
        return age;
    }
};
int main(){
    Person tom("Tom", 38);   // // создаем объект - вызываем конструктор
    // Person tom{"Tom", 38};
    // Person tom = Person("Tom", 38);
    tom.setAge(22);     // изменяем возраст
    tom.setAge(123);
    tom.print();               // Name: Tom   Age: 22
    std::cout << tom.getAge() << tom.getName();

//    Person person;   // когда нет конструктора
//    person.name = "Tom";
//    person.age = 38;
//    person.print();
}
