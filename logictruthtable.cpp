/// Truth table generator for 5 bit signed addition/subtraction to be compared with the truth table generated from LogiSim

#include<fstream>
#include<bitset>
using namespace std;

//                                 8       4       2       1
int Signed_5Bit_Adder(int ai,int a1, int b1, int c1, int d1, int e1, int a2, int b2, int c2, int d2, int e2)
{
	int num1, num2, sum;
	num1 = b1*8 + c1 * 4 + d1 * 2 + e1 * 1;
	num1 = a1==1 ? -1*num1 : num1;  
	num2 = b2*8 + c2 * 4 + d2 * 2 + e2 * 1;
	num2 = a2==1 ? -1*num2 : num2;
	if (ai == 0)
		sum = num1+ num2;
	else
		sum = num1- num2;
	return sum;
}

int main()
{
	ofstream TruthTable("magn2.txt" , ios::out);
	//TruthTable << "##############   ADDITION   ##############" << endl << endl;
	//TruthTable << "A1\tB1\tC1      D1      E1   +  A2      B2      C2      D2      E2     ==>          ANSWER  " << endl;
	int answer;
	for (int ai = 0; ai < 2; ai++)
	{
		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < 2; b++)
			{
				for (int c = 0; c < 2; c++)
				{
					for (int d = 0; d < 2; d++)
					{
						for (int e = 0; e < 2; e++)
						{
							for (int f = 0; f < 2; f++)
							{
								for (int g = 0; g < 2; g++)
								{
									for (int h = 0; h < 2; h++)
									{
										for (int i = 0; i < 2; i++)
										{
											for (int j = 0; j < 2; j++)
											{
												answer =Signed_5Bit_Adder(ai,a,b,c,d,e,f,g,h,i,j);
												
												TruthTable << ai << "\t" << a << "\t"  << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t";
												if (answer >= 0 ) {
													 TruthTable << "0\t";
												}
												else {
													TruthTable << "1\t";
													answer *=-1;
												}
												bitset<5> x(answer);
												for (int l = 4 ; l > 0; l--)
													TruthTable << x[l] << "\t";
												TruthTable << x[0];
												TruthTable << endl;
											}
										
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	TruthTable.close();

	return 0;
}
