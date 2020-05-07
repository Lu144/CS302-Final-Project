#include <boost/graph/adjacency_list.hpp>
#include <iostream>

using namespace std;

struct CityVertex {
    string cityName;
};

int main(){
    typedef boost::adjacency_list<boost::vecS, boost::vecS,
   								 boost::undirectedS,
   								 CityVertex,
   								 boost::property<boost::edge_weight_t, int>>
   								 RouteMap;
    RouteMap salesmanMap(5);

    salesmanMap[0].cityName = "Reno";
    salesmanMap[1].cityName = "Salt Lake City";
    salesmanMap[2].cityName = "Las Vegas";
    salesmanMap[3].cityName = "Seattle";
    salesmanMap[4].cityName = "San Francisco";
    

    // Insert Reno connections
    add_edge(0, 1, 518, salesmanMap); //to Salt Lake
    add_edge(0, 2, 439, salesmanMap); //to Las Vegas
    add_edge(0, 3, 704, salesmanMap); //to Seattle
    add_edge(0, 4, 218, salesmanMap); //to San Fran

    // Insert Salt Lake City connections
    add_edge(1, 2, 421, salesmanMap); //to Las Vegas
    add_edge(1, 3, 829, salesmanMap); //to Seattle
    add_edge(1, 4, 736, salesmanMap); //to San Fran

    //Insert Las Vegas Connections
    add_edge(2, 3, 1115, salesmanMap); //to Seattle
    add_edge(2, 4, 569, salesmanMap); //to San Fran

    // Insert final connection between Seattle and San Francisco
    add_edge(3, 4, 808, salesmanMap);

    boost::property_map<RouteMap, boost::edge_weight_t>::type weightmap = get(boost::edge_weight, salesmanMap);

    int index[4] = {1,2,3,4};

    int smallestDistance = INT_MAX;

    do {
   		cout << endl;
   		int distance = 0;
   		auto outEdgePair = out_edges(0, salesmanMap);
   		for (auto outEdgeStart = outEdgePair.first; outEdgeStart != outEdgePair.second; outEdgeStart++){
   			if (target(*outEdgeStart, salesmanMap) == index[0]) {
   				cout << "Reno to " << salesmanMap[target(*outEdgeStart, salesmanMap)].cityName << " is " << weightmap[*outEdgeStart] << endl;
   				distance += weightmap[*outEdgeStart];
   			}
   		 }

   		 for (int i = 0; i < 3; i++){
   			auto outEdgePair = out_edges(index[i], salesmanMap);
   			for (auto outEdgeStart = outEdgePair.first; outEdgeStart != outEdgePair.second; outEdgeStart++){
   				if (target(*outEdgeStart, salesmanMap) == index[i+1]){
   					cout << salesmanMap[source(*outEdgeStart, salesmanMap)].cityName << " to " << salesmanMap[target(*outEdgeStart, salesmanMap)].cityName << " is " << weightmap[*outEdgeStart] << endl;
   				    distance += weightmap[*outEdgeStart];
   				}
   			}
   		}

   		outEdgePair = out_edges(3, salesmanMap);
   		for (auto outEdgeStart = outEdgePair.first; outEdgeStart != outEdgePair.second; outEdgeStart++){
   			if (target(*outEdgeStart, salesmanMap) == 0) {
   				cout << salesmanMap[source(*outEdgeStart, salesmanMap)].cityName << " to Reno is " << weightmap[*outEdgeStart] << endl;
   				distance += weightmap[*outEdgeStart];
   			}
   		}

   	if (distance < smallestDistance) smallestDistance = distance;
   	cout << "Total distance: " << distance << endl;
   	cout << "====STARTING NEW ROUTE CALCULATION====\n" << endl;


    } while (next_permutation(index, index+4));

    cout << "The shortest possible distance is " << smallestDistance << endl;

    cout << "The route: " << salesmanMap[0].cityName << " -> ";
    for (int i = 0; i < 4; i++){
   	 	cout << salesmanMap[index[i]].cityName << " -> ";
    }
    cout << salesmanMap[0].cityName << endl;

}
