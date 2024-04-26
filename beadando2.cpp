#include <vector>
#include <iostream>

using namespace std;

struct pol
{
    vector<double> coeff;
    pol(){};
    pol(const vector<double>& i) : coeff(i){};
    pol(const int& j): coeff(j, 0.0){};

    pol operator+(const pol& p) const
    {
    
        pol osszeg(coeff);

        int size = max(coeff.size(), p.coeff.size());

        for(int i = 0; i < size; ++i){
            double e1 = (i < coeff.size()) ? coeff[i] : 0;
            double e2 = (i < p.coeff.size()) ? p.coeff[i] : 0;

            osszeg.coeff[i] = e1 + e2;
        }
        return osszeg;
        };
    
    pol operator-(const pol& p) const {

        pol kul(coeff);

        int size = max(coeff.size(), p.coeff.size());

        for(int i = 0; i < size; ++i){
            double e1 = (i < coeff.size()) ? coeff[i] : 0;
            double e2 = (i < p.coeff.size()) ? p.coeff[i] : 0;

            kul.coeff[i] = e1 - e2;
        }
        return kul;
        }

    pol operator*(const pol& p) const{

        pol szorzat(coeff.size() + p.coeff.size() - 1);

        for(int i = 0; i < coeff.size(); ++i){
            for(int j = 0; j < p.coeff.size(); ++j){
                szorzat.coeff[i+j] += coeff[i] * p.coeff[j];
            }
        }
        return szorzat;
        }

    pol diff() const {
        
        pol difform(coeff.size()-1);

        for(int i = 0; i < coeff.size(); ++i){
            difform.coeff[i] = i * coeff[i+1];
        }
        return difform;
        }

    /// @brief //őszíntén itt ötletem nincs miért de debugger itt errort adott es ezzel quickfixelte, aztán így se akar működni, nem teljesen értem
    void print(){

    
        for(int i = 0; i < coeff.size(); ++i){
            if(i > 0){
                cout << " + " << coeff[i] << "x^"<< i;
            }
            if(i < 0){
                cout << coeff[i] << "x^"<< i;
            }
        }
    }
};

int main()
{
    std::cout << "Hello World" << std::endl;

    return 0;
}
