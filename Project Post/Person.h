
#ifndef POSTOFFICE_PERSON_H
#define POSTOFFICE_PERSON_H


class Person {
public:
    Person();
    Person(const char* name, const char* ucn);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    void setName(const char *name);
    void setUcn(const char *ucn);

    void print() const;

protected:
    char* name;
    char* ucn;

private:
    bool isNumeric(const char* ucn);

    void destroy();
};


#endif //POSTOFFICE_PERSON_H
