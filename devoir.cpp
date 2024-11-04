#include <iostream>
#include<typename T>
using namespace std;
//question 1:
class NombreComplexe{
    private:
     T reel;
     T imaginaire;
    public:
 //question 3:
 NombreComplexe()reel(0),imaginaire(0){};
 NombreComplexe(T re, T im):reel(re),imaginaire(im){};
 NombreComplexe( NombreComplexe const T &c){};
 //question 4:
 void afficher(){
 cout<<"le nombre complexe est :"<<endl;
 if( imaginaire<0){
 cout<<reel<<"-"<<imaginaire<<"i"<<endl;
 }
cout<<reel<<"+"<<imaginaire<<"i"<<endl;
 }
//question 5:
  NombreComplexe operator+(const NombreComplexe &c1){
    T re= reel+c1.reel;
    T im= imaginaire+c1.imaginaire;
    return NombreComplexe(re,im);
}
 // Surcharge de l'opérateur - (soustraction)
    NombreComplexe operator-(const NombreComplexe& other) const {
        return NombreComplexe(reel - other.reel, imaginaire - other.imaginaire);
    }

    // Surcharge de l'opérateur * (multiplication)
    NombreComplexe operator*(const NombreComplexe& other) const {
        T r = reel * other.reel - imaginaire * other.imaginaire;
        T i = reel * other.imaginaire + imaginaire * other.reel;
        return NombreComplexe(r, i);
    }

    // Surcharge de l'opérateur / (division)
    NombreComplexe operator/(const NombreComplexe& other) const {
        T denom = other.reel * other.reel + other.imaginaire * other.imaginaire;
        T r = (reel * other.reel + imaginaire * other.imaginaire) / denom;
        T i = (imaginaire * other.reel - reel * other.imaginaire) / denom;
        return NombreComplexe(r, i);
    }
    //question 6:
    // Surcharge des opérateurs de comparaison ==
    bool operator==(const NombreComplexe& other) const {
        return (reel == other.reel && imaginaire == other.imaginaire);
    }

    // Surcharge des opérateurs de comparaison !=
    bool operator!=(const NombreComplexe& other) const {
        return !(*this == other);
    }

    // Surcharge des opérateurs de comparaison <
    bool operator<(const NombreComplexe& other) const {
        return std::sqrt(reel * reel + imaginaire * imaginaire) < std::sqrt(other.reel * other.reel + other.imaginaire * other.imaginaire);
    }

    // Surcharge des opérateurs de comparaison >
    bool operator>(const NombreComplexe& other) const {
        return other < *this;
    }

    // Surcharge des opérateurs de comparaison <=
    bool operator<=(const NombreComplexe& other) const {
        return !(*this > other);
    }

    // Surcharge des opérateurs de comparaison >=
    bool operator>=(const NombreComplexe& other) const {
        return !(*this < other);
    }

};
//question 7:
int main() {
    // Création d'objets de type NombreComplexe<int>
    NombreComplexe<int> a(3, 4);
    NombreComplexe<int> b(1, -2);
    NombreComplexe<int> c(a);  // Utilise le constructeur de copie

    cout << "Nombre complexe a : ";
    a.afficher();

    cout << "Nombre complexe b : ";
    b.afficher();

    cout << "Nombre complexe c (copie de a) : ";
    c.afficher();

    // Test des opérateurs arithmétiques
    NombreComplexe<int> somme = a + b;
    cout << "Somme de a et b : ";
    somme.afficher();

    NombreComplexe<int> difference = a - b;
    cout << "Différence entre a et b : ";
    difference.afficher();

    NombreComplexe<int> produit = a * b;
    cout << "Produit de a et b : ";
    produit.afficher();

    NombreComplexe<int> quotient = a / b;
    cout << "Quotient de a et b : ";
    quotient.afficher();

    // Test des opérateurs de comparaison
    cout << "a == b : " << (a == b ? "Vrai" : "Faux") << std::endl;
    cout << "a != b : " << (a != b ? "Vrai" : "Faux") << std::endl;
    cout << "a < b : " << (a < b ? "Vrai" : "Faux") << std::endl;
    cout << "a > b : " << (a > b ? "Vrai" : "Faux") << std::endl;
    cout << "a <= b : " << (a <= b ? "Vrai" : "Faux") << std::endl;
    cout << "a >= b : " << (a >= b ? "Vrai" : "Faux") << std::endl;

    return 0;
}
