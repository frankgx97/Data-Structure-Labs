#include "stdafx.h"
#include "JosephusCircle.h"

int main()
{
	JosephusCircle circle(9,1,5);
	circle.start_circle();
	JosephusCircle circle1(9,1,0);
	circle1.start_circle();
	JosephusCircle circle2(9,1,10);
	circle2.start_circle();
	system("pause");
}