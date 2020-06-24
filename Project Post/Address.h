
#ifndef POSTOFFICE_ADDRESS_H
#define POSTOFFICE_ADDRESS_H


class Address {
public:
    Address();
    Address(const char* town, char entrance, int apt, const char* street, const char* building);
    Address(const Address& other);
    Address& operator=(const Address& other);
    virtual ~Address();

    bool operator==(const Address& other) const;

    void setTown(const char *town);
    void setStreet(const char *street);
    void setBuilding(const char *building);
    void setEntrance(char entrance);
    void setApt(int apt);

    void print() const;

protected:
    char* town;
    char* street;
    char* building;
    char entrance;
    int apt;

private:
    void destroy();
};


#endif //POSTOFFICE_ADDRESS_H
