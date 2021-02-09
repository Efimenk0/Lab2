#ifndef DELTOID_H
#define DELTOID_H

#include <cmath>
#include <string>
#include <stdexcept>


namespace Del {
    class Deltoid {
        double r;
    public:
       
        Deltoid(double r = 1);
     
        Deltoid& setr(double);
       
        double getr() const { return r; };
      
        double get_length_of_intersection() const;
        
        double get_length() const;
      
        double  get_area() const;
        
        Deltoid& get_coords(double, double&, double&);
      
        std::string equation() const;


    };

}


#endif // !DELTOID_H


