#pragma once

namespace POCU3200Midterm
{
    class Subone
    {
    public:
        Subone(int x, int y);

		// As move constructor is there, deleted copy constructor 아니 얘체 언제 생기고 사라진느거야 쉬발럼아
		Subone(const Subone& other);


		// 동적할당리소스가있으면 const가 안붙는게 정상일듯?
		Subone(Subone&& other) noexcept; // move constructor, resource acquisition by hand over, not initialization
        ~Subone();
        void Submethod();

        Subone& operator=(const Subone& other);
		void operator=(Subone&& other) noexcept;

    private:
        int* mpSuboneX;
        int* mpSuboneY;
        int mSuboneIntegers[2]; // member array elements are also subobject. need initialization action.
    };

}