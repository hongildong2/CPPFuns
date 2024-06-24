#pragma once
namespace POCU3200Midterm
{
    class IBar
    {
    public:
    virtual void Say() const = 0;
    virtual void BarVirtualMethod() = 0;
    virtual void PureVirtualMethod() = 0;
    };
}

