#pragma once


template<int I>
class Black final
{
public:
	
	void Disaster()
	{
		static_assert(I > MAGIC, " I IS TOO SMALL ");

		int out = 3;
		int captureThisRef = -100;
		auto lambda = [=, &captureThisRef, VarInCaptureClause = " i am in capture clause lol "](int param)
		{
			std::cout << VarInCaptureClause << std::endl;
			std::cout << "lambda param usage is just same as func :: " << param << std::endl;

			// private member access allowed and works
			this->m_secret = 1;

			// Disaster(); // infinite

			captureThisRef = 123123;

			return 1;
		};

		int a = lambda(I);
	}

	static constexpr int MAGIC = 10;

private:
	int m_secret;
};



constexpr int square(int n)
{
	Black<12321312> dd;
	return n * n;
}

constexpr int SQUARED_2 = square(2);
static const int SQUARED_3 = square(3);

static const int SQR__SQR_2 = square(SQUARED_2);


template<typename T>
constexpr T WhatISTHIS(T t)
{
	return t;
}

int a = WhatISTHIS(3);

template<>
constexpr double WhatISTHIS<double>(double d)
{
	return d;
}

double d = WhatISTHIS(3.0);




class Bye final
{
	public:
	constexpr Bye(int d) 
	 : m_a(d)
	{}

	int m_a;
};

int x = 1;


// constexpr Bye a(x); // not a constant expression

constexpr Bye asdasd(1); // const expression