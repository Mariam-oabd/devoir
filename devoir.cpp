#include <iostream>
#include <cmath>  
using namespace std;

// Question 1:
template<typename T>
class NombreComplexe {
private:
    T reel;
    T imaginaire;

public:
    // Question 3:
    NombreComplexe() : reel(0), imaginaire(0) {}  // Default constructor
    NombreComplexe(T re, T im) : reel(re), imaginaire(im) {}  // Parameterized constructor
    NombreComplexe(const NombreComplexe& c) : reel(c.reel), imaginaire(c.imaginaire) {}  // Copy constructor

    // Question 4:
    void afficher() const {
        cout << "Le nombre complexe est : ";
        if (imaginaire < 0) {
            cout << reel << imaginaire << "i" << endl;
        } else {
            cout << reel << "+" << imaginaire << "i" << endl;
        }
    }

    // Question 5:
    NombreComplexe operator+(const NombreComplexe& c1) const {
        T re = reel + c1.reel;
        T im = imaginaire + c1.imaginaire;
        return NombreComplexe(re, im);
    }

    // Overload - operator
    NombreComplexe operator-(const NombreComplexe& other) const {
        return NombreComplexe(reel - other.reel, imaginaire - other.imaginaire);
    }

    // Overload * operator
    NombreComplexe operator*(const NombreComplexe& other) const {
        T r = reel * other.reel - imaginaire * other.imaginaire;
        T i = reel * other.imaginaire + imaginaire * other.reel;
        return NombreComplexe(r, i);
    }

    // Overload / operator
    NombreComplexe operator/(const NombreComplexe& other) const {
        T denom = other.reel * other.reel + other.imaginaire * other.imaginaire;
        T r = (reel * other.reel + imaginaire * other.imaginaire) / denom;
        T i = (imaginaire * other.reel - reel * other.imaginaire) / denom;
        return NombreComplexe(r, i);
    }

    // Question 6:
    bool operator==(const NombreComplexe& other) const {
        return (reel == other.reel && imaginaire == other.imaginaire);
    }

    bool operator!=(const NombreComplexe& other) const {
        return !(*this == other);
    }

    bool operator<(const NombreComplexe& other) const {
        return std::sqrt(reel * reel + imaginaire * imaginaire) < std::sqrt(other.reel * other.reel + other.imaginaire * other.imaginaire);
    }

    bool operator>(const NombreComplexe& other) const {
        return other < *this;
    }

    bool operator<=(const NombreComplexe& other) const {
        return !(*this > other);
    }

    bool operator>=(const NombreComplexe& other) const {
        return !(*this < other);
    }
};

// Question 7:
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
    cout << "a == b : " << (a == b ? "Vrai" : "Faux") << endl;
    cout << "a != b : " << (a != b ? "Vrai" : "Faux") << endl;
    cout << "a < b : " << (a < b ? "Vrai" : "Faux") << endl;
    cout << "a > b : " << (a > b ? "Vrai" : "Faux") << endl;
    cout << "a <= b : " << (a <= b ? "Vrai" : "Faux") << endl;
    cout << "a >= b : " << (a >= b ? "Vrai" : "Faux") << endl;

    return 0;
}
