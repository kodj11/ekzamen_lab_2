#include <iostream>
#include <cmath>
using namespace std;

// Abstract class kakogo-to tela
// Abstract -> Iz-za virtual double Volume() const = 0;
class Body {
private:
    // Plotnost' 
    // zashita - private
    double density_;

public:
    Body(double density) : density_(density) {}
    // Chisto abstract
    virtual double Volume() const = 0;
    // Massa = plotnost' * znachenie y potomkov
    double Mass() const {
        return density_ * Volume();
    }
    // virtual dest tela
    virtual ~Body() {
        density_ = 0;
    }
};

class Cube : public Body {
private:
    // rebro cuba
    double edge_;

public:
    // construct 1 parametr - rebro
    //           2 parametr - plotnost'
    Cube(double edge, double density) : Body(density), edge_(edge) {}
    // Znachenie cuba
    double Volume() const {
        return edge_ * edge_ * edge_;
    }
    // virtual dest cuba
    virtual ~Cube() {
        edge_ = 0;
    }
};

class Tetrahedron : public Body {
private:
    // Dlina rebra tetraidera
    double edge_;

public:
    // construct 1 parametr - rebro
    //           2 parametr - plotnost'
    Tetrahedron(double edge, double density) : Body(density), edge_(edge) {}
    // Znachenie tetraidera
    double Volume() const {
        return edge_ * edge_ * edge_ / (6 * sqrt(2));
    }
    // virtual dest tetraidera
    virtual ~Tetrahedron() {
        edge_ = 0;
    }
};

int main() {
    const Body *p, *q, *r;
    Cube a(2, 10), b(5, 0.1);
    Tetrahedron t(6, 2.5);
    p = &a; q = &b; r = &t;

    printf("Volumes: %.3f %.3f %.3f\n",
        p->Volume(), q->Volume(), r->Volume());
    printf("Weights: %.3f %.3f %.3f\n",
        p->Mass(), q->Mass(), r->Mass());

    return 0;
}
