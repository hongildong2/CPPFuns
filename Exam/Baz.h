#pragma once
#include "Bar.h"
#include "IBar.h"

namespace POCU3200Midterm
{
    class Baz :
        public Bar, IBar
    {
    public:
        Baz(int x);
        ~Baz();
        // What does this "Say" method will inherit if not specified? Bar's?

        void Say() const override;
        void BarVirtualMethod() override;
        void PureVirtualMethod() override;
    private:
        int mBazX;

        // Inherited via IBar
    };

}