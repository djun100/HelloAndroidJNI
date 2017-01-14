
// myMeanSum.h文件
#pragma once

#include <stdio.h>
#include <stdlib.h>

class myMeanSum
{
public:
	myMeanSum();
	~myMeanSum();
	myMeanSum(int* data, int num);
	
	double calcMean();
	int calcSum();

private:
	int m_number;
	int* databuf;
	double m_mean;
	int m_sum;
};

