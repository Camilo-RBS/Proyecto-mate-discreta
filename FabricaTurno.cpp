#include <iostream>
#include <random>

using namespace std;

void probabilidad(int, int, int, int);

int main() {
   
    random_device rd;
    mt19937 gen(rd());

    double T1 = 0.4;
    double T2 = 0.35;
    double T3 = 0.25;

    double DefecT1 = 0.01;
    double DefecT2 = 0.02;
    double DefecT3 = 0.03;
    
    int DT2 = 0;
    int DT3 = 0;
    int TotalDe = 0;
    int n;

    cout << "Ingrese el numero de iteraciones que desea que realice el experimento: ";
    cin >> n;

   

    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        double turno = dis(gen);

        if (turno < T1) {
            double defectuoso = dis(gen);
            if (defectuoso < DefecT1) {
                TotalDe++;
            }
        } else if (turno < T1 + T2) {
            double defectuoso = dis(gen);
            if (defectuoso < DefecT2) {
                TotalDe++;
                DT2++;
            }
        } else {
            double defectuoso = dis(gen);
            if (defectuoso < DefecT3) {
                TotalDe++;
                DT3++;
            }
        }
    }

    probabilidad(TotalDe, DT2, DT3, n);
    return 0;
}

void probabilidad(int a, int b, int c, int n) {
    double T1 = static_cast<double>(a) / n;
    double T2 = (a > 0) ? static_cast<double>(b) / a : 0.0;
    double T3 = (a > 0) ? static_cast<double>(c) / a : 0.0;

    cout << "Cual es la probabilidad de que resulte defectuoso? R:  " << T1 << endl;
    cout << "Cual es la probabilidad de que haya sido producido en el turno T2 ? R: " << T2 << endl;
    cout << "en el turno T3? R: " << T3 << endl;
}