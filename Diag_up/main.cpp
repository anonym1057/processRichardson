#include "GeneralizedProcessR.h"
#include "Standarddeviation.h"
#include "diagram2.h"
#include <iostream>
#include <fstream>
#include <string>

void pr_r_for_in();
int main(void)
{
	pr_r_for_in();
	return 0;
}


void pr_r()
{
	int count = 10000;
	GeneralizedProcessR * d = new GeneralizedProcessR();
	StandardDeviation* s = new StandardDeviation(count + 1);

	d->generalized_processR(count,-0.37);
	d->print_in_file_col("col_037_aver1.txt");
	std::cout << "_" << s->SD_gener_process(*d);
	d->print_picture();
	delete d;
	delete s;
}


void pr_r_for()
{
	int count = 10000;
	GeneralizedProcessR * d = new GeneralizedProcessR();
	StandardDeviation* s = new StandardDeviation(count + 1);
	string tr = "col10x100_";
	string  en = ".txt";

	ofstream fout;
	fout.open("alpha_10x100_1.txt");
	if (!fout.is_open()) {
		std::cout << "Error: file don't open\n";
	}


	for (double a = -0.6; a <= -0.2; a += 0.015)
	{
		std::cout << a << "\n";
		d->generalized_processR(count,a,100);
		d->print_in_file_col(tr+std::to_string(a)+en);
		fout << a << "\t" << s->SD_gener_process(*d) << "\n";
		d->clear();
	}
	fout.close();

	delete d;
	delete s;
}


void pr_r_for_in()
{
	int count = 10000;

	StandardDeviation* s = new StandardDeviation(1);
	string tr = "file\\col10x100_";
	string  en = ".txt";

	Diagram2 * d;

	ofstream fout;
	fout.open("alpha_10x100_2.txt");
	if (!fout.is_open()) {
		std::cout << "Error: file don't open\n";
	}


	for (double a = -0.6; a <= -0.2; a += 0.015)
	{
		std::cout << a << "\n";
		d = new Diagram2(tr + std::to_string(a) + en);
		fout << a << "\t" << s->SD_gener_process(*d) << "\n";
		delete d;
	}
	fout.close();

	delete s;
}