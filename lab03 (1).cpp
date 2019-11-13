#include<iostream>
#include<cmath>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::abs;

double fn(double x) {
	return -6.0 * pow(x,2.0) + 5.0 * x + 3.0;
}

double integral(double x) {
	return -2.0 * pow(x, 3.0) + (5.0 / 2.0) * pow(x, 2.0) + 3.0 * x;
}

double trapezoid(double a, double b, long n) {
	double w;
	double h;
	double f;
	w = (b - a) / n;
	h = a + w;
	f = 0;
	while (1) {
		if (b > a) {
			f = f+ w * (fn(a) + fn(h)) / 2;
			a += w;
			h += w;
		} else {
			break;
		}
	}
	return f;
}

int main() {
	double a;
	double b;
	double tolerance;
	long n;
	cin >> a;
	cin >> b;
	cin >> tolerance;
	cin >> n;
	cout << "Lower" << ' ' << "Range:"  << endl;
	cout << "Upper" << ' ' << "Range:" << endl;
	cout << "Tolerance:" <<  endl;
	cout << "Initial" << ' ' << "trapezoid" << ' ' << "count:"  << endl;
	while (1) {
		double exact_value;
		double estimate_value;
		double diff;
		exact_value = integral(b) - integral(a);
		estimate_value = trapezoid(a, b, n);
		diff = abs(exact_value - estimate_value);
		if (diff >= tolerance) {
			cout << "Intermediate Result:" << fixed << setprecision(4) << estimate_value << ','
				<< " traps:" << fixed << setprecision(4) << n << ',' 
				<< " diff:" << fixed << setprecision(4) << diff << endl;
			n *= 2;
			continue;
		} else if(diff <= tolerance) {
			cout << "Trap count:" << fixed << setprecision(4) << n << ','
				<< " estimate:" << fixed << setprecision(4) << estimate_value
				<< ',' << " exact:" << fixed << setprecision(4) << exact_value
				<< ',' << " tolerance:" << fixed << setprecision(4) << tolerance << endl;
			break;
		}
	}
}