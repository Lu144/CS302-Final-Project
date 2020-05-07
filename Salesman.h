
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
      min_distance(0);
      cout << "The shortest distances is: " << distance << endl;
    }
    void setDistances() {
      distances = {{0,218,439,518,704},
                  {218,0,569,736,808},
                  {439,569,0,421,1125},
                  {518,736,421,0,830},
                  {704,808,1125,830,0}};
    }
    int shortest(int city) {
	int nc = 999;
	int min = 999, kmin;
 
	for(int i = 0; i < cities; i++) {
		if((distances[city][i] != 0) && (final_route[i] == 0)) {
			if(distances[city][i] + distances[i][city] < min) {
				min = distances[i][0] + distances[city][i];
				kmin = distances[city][i];
				nc = i;
			}
		}
	}
 
	if(min != 999) {
		cost += kmin;
	}
 
	return nc;
}
	
	
    void min_distance(int city) {
	int temp, citytemp;
	final_route[city] = 1;
	cout << city + 1 << " -->";
	citytemp = shortest(city);
	    
	if(citytemp == 999) {
	    citytemp = 0;
	    cout << citytemp +1;
	    distance += distances[city][citytemp];
	}
	min_distance(citytemp);
    }
  
  private:
    int cities;
    int distances[5][5];
    int final_route[5];
    int distance;
  
}
  
#endif
