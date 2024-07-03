#pragma once

namespace POCU3200Midterm
{
    class Subone
    {
    public:
        Subone(int x, int y);

		// As move constructor is there, deleted copy constructor �ƴ� ��ü ���� ����� ��������ž� ���߷���
		Subone(const Subone& other);


		// �����Ҵ縮�ҽ��������� const�� �Ⱥٴ°� �����ϵ�?
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