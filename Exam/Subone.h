#pragma once

namespace POCU3200Midterm
{
    class Subone
    {
    public:
        Subone(int x, int y);
        ~Subone();
        void Submethod();

    private:
        int* mpSuboneX;
        int* mpSuboneY;
        int mSuboneIntegers[2]; // member array elements are also subobject. need initialization action.
    };

}