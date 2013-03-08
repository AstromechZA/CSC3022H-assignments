#include <iostream>
#include <string>
#include <map>

#include "noisy.h"

using namespace std;

noisy& g(noisy& n)
{
    cout << "Entering into g()" << endl;
    cout << "Returning from g()" << endl;
    return n;
} 

noisy& f(noisy & n)
{
    cout << "Entering into f()" << endl;
    noisy & ret = g(n);
    cout << "Returning from f()" << endl;
    return ret;
}

// Adds two noisy rational numbers together, creating
// a new object
noisyrat addrats(const noisyrat & lhs, const noisyrat & rhs)
{
    return noisyrat(
        lhs.get_n()*rhs.get_d() + rhs.get_n()*lhs.get_d(),
        lhs.get_d()*rhs.get_d());
}

// Adds the value of rhs, to that of lhs and returns lhs
noisyrat & addtorat(noisyrat & lhs, const noisyrat & rhs)
{
    lhs.set_n(lhs.get_n()*rhs.get_d() + rhs.get_n()*lhs.get_d()) ;
    lhs.set_d(lhs.get_d()*rhs.get_d());
    return lhs;
}

int main(void)
{
    cout << "PART ONE" << endl;

    {
        noisy var1("VAR1");
        noisy & var2 = f(var1);
        noisy * var3 = new noisy("VAR3");
        var3 = &var1;
    }


    cout << "PART TWO" << endl;

    {
        noisyrat nr1(1,2);
        noisyrat nr2(3,4);
        noisyrat nr3(5,6);

        cout << "PART TWO: Calling addrats()" << endl;
        cout << "PART TWO: addrats return value=" << addrats(nr1, addrats(nr2,nr3)) << endl;
        cout << "PART TWO: Final value of nr1=" << nr1 << " nr2=" << nr2 << " nr3=" << nr3 << endl;
        cout << "PART TWO: calling addtorats()" << endl;
        cout << "PART TWO: addtorat return value=" << addtorat(nr1, addtorat(nr2,nr3)) << endl;
        cout << "PART TWO: Final value of nr1=" << nr1 << " nr2=" << nr2 << " nr3=" << nr3 << endl;
    }



    cout << "PART THREE" << endl;


    map<string, int> animalmap;

    animalmap["zebras"] = 2;
    animalmap["tigers"] = 3;
    animalmap["budgies"] = 10;

    cout << "animalmap contains:" << endl;
    for (map<string, int>::iterator current = animalmap.begin(), end = animalmap.end(); current != end; ++current)
        cout << current->first << " => " << current->second << endl;

    cout << "erasing zebras" << endl;
    animalmap.erase("zebras");

    cout << "animalmap contains:" << endl;
    for (map<string, int>::iterator current = animalmap.begin(), end = animalmap.end(); current != end; ++current)
        cout << current->first << " => " << current->second << endl;

    cout << "Returning from main" << endl;

    
}

