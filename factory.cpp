#include <iostream>


/* Create a Furniture Abstract Factory
*/

class IChair
{
public:
    virtual ~IChair() = default;
    virtual void PrintChairInfo() = 0;
};

class VictorianChair : public IChair
{
    void PrintChairInfo()
    {
        std::cout << "Victorian Chair" << std::endl;
    }
};

class ModernChair : public IChair
{
    void PrintChairInfo()
    {
        std::cout << "Modern Chair" << std::endl;
    }
};
//------

class ISofa
{
public:
    virtual ~ISofa() = default;
    virtual void PrintSofaInfo() = 0;
};

class VictorianSofa : public ISofa
{
    void PrintSofaInfo()
    {
        std::cout << "Victorian Sofa" << std::endl;
    }
};

class ModernSofa : public ISofa
{
    void PrintSofaInfo()
    {
        std::cout << "Modern Sofa" << std::endl;
    }
};
//------

class ITable
{
public:
    virtual ~ITable() = default;
    virtual void PrintTableInfo() = 0;
};

class VictorianTable : public ITable
{
    void PrintTableInfo()
    {
        std::cout << "Victorian Table" << std::endl;
    }
};

class ModernTable : public ITable
{
    void PrintTableInfo()
    {
        std::cout << "Modern Table" << std::endl;
    }
};

//------

class IFurnitureFactory
{
public:
    virtual ~IFurnitureFactory() = default;
    virtual IChair* BuildChair() = 0;
    virtual ISofa* BuildSofa() = 0;
    virtual ITable* BuildTable() = 0;
};

class VictorianFurnitureFactory: public IFurnitureFactory
{
public:
    IChair* BuildChair() { return new VictorianChair(); }
    ISofa* BuildSofa() { return new VictorianSofa(); }
    ITable* BuildTable() { return new VictorianTable(); }
};

class ModernFurnitureFactory: public IFurnitureFactory
{
public:
    IChair* BuildChair() { return new ModernChair(); }
    ISofa* BuildSofa() { return new ModernSofa(); }
    ITable* BuildTable() { return new ModernTable(); }
};



//---------------------------------------
// Extended the Abstract Factory function design pattern ....

class NeoChair : public IChair
{
    void PrintChairInfo()
    {
        std::cout << "Neo Chair" << std::endl;
    }
};

class NeoSofa : public ISofa
{
    void PrintSofaInfo()
    {
        std::cout << "Neo Sofa" << std::endl;
    }
};

class NeoTable : public ITable
{
    void PrintTableInfo()
    {
        std::cout << "Neo Table" << std::endl;
    }
};

class NeoFurnitureFactory: public IFurnitureFactory
{
public:
    IChair* BuildChair() { return new NeoChair(); }
    ISofa* BuildSofa() { return new NeoSofa(); }
    ITable* BuildTable() { return new NeoTable(); }
};
//---------------------------------------




int main()
{
    std::cout << "Sample for Abstract Factory Design Pattern!" << std::endl;

    IFurnitureFactory* factory = nullptr;

    factory = new VictorianFurnitureFactory();
    factory->BuildChair()->PrintChairInfo();
    factory->BuildSofa()->PrintSofaInfo();
    factory->BuildTable()->PrintTableInfo();
    delete factory;

    factory = new ModernFurnitureFactory();
    factory->BuildChair()->PrintChairInfo();
    factory->BuildSofa()->PrintSofaInfo();
    factory->BuildTable()->PrintTableInfo();
    delete factory;

    factory = new NeoFurnitureFactory();
    factory->BuildChair()->PrintChairInfo();
    factory->BuildSofa()->PrintSofaInfo();
    factory->BuildTable()->PrintTableInfo();
    delete factory;

    return 0;
}