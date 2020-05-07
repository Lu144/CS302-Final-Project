
#ifndef SALESMAN_H_
#define SALESMAN_H_

using namespace std;

class Salesman {
  public:
    Salesman() {
      cities = 0;
    }
    Salesman(int num_cities) {
      cities = num_cities;
      setDistances();
    }
    void setDistances() {
      distances = {{0,218,439,518,704},
                  {218,0,569,736,808},
                  {439,569,0,421,1125},
                  {518,736,421,0,830},
                  {704,808,1125,830,0}};
    }
	 
  
  private:
    int cities;
    int distances[5][5];
    int final_route[5];
    
  
}
  
#endif
