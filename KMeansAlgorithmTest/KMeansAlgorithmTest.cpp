// KMeansAlgorithmTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "math.h"
using namespace std;
class Centroid{
private:
	double centP[2]; //Cx = centP[0], Cy = centP[1]
	double points[2][2];// Xn = points[n][0], Yn = points[n][1]
public:
	Centroid(){
		centP[0] = 0;
		centP[1] = 0;
	}
	void setPoints(double p1[2], double p2[2]){
		for(int i = 0; i<2; i++){
			points[0][i] = p1[i];
			points[1][i] = p2[i];
		}
	}
	double getDistance(double p[2]){
		return sqrt(((centP[0] - p[0])*(centP[0] - p[0]))+((centP[1] - p[1])*(centP[1] - p[1])));
	}
	double* getGrad(){
		double LxSum = 0;
		double LySum = 0;
		for(int i = 0; i<2; i++){
			LxSum+=(centP[0] - points[i][0])/getDistance(points[i]);
			LySum+=(centP[1] - points[i][1])/getDistance(points[i]);
		}
		LxSum/=2.0;
		LySum/=2.0;
		double L[2] = {LxSum, LySum};
		return L;
	}
	void changeCent(double delX, double delY){
		//double n = (sqrt((points[0][0]-points[1][0])*(points[0][0]-points[1][0]))+sqrt((points[0][1]-points[1][1])*(points[0][1]-points[1][1])))/2;
		double n = 1.0;
		centP[0]-=n*delX;
		centP[1]-=n*delY;
	}
	double* getCent(){
		return centP;
	}

};
int main()
{
	Centroid tester;
	double a[2] = { 6.0,0.0 };
	double b[2] = { 6.0,1.0 };
	double* grad = NULL;
	double* cent = NULL;
	for (int i = 0; i < 10000; i++) {
		tester.setPoints(a, b);
		grad = tester.getGrad();
		tester.changeCent(*grad, *(grad + 1));
		cout << *grad << " " << *(grad + 1) << endl;
		cent = tester.getCent();
		cout << "( " << *cent << ", " << *(cent + 1) << " ) " << endl;
	}
	cin.ignore();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
