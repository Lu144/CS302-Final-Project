//Name: CS302 Final Project - Travelling Salesman Problem
//Purpose:

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/dijkstra_shortest_paths.hpp"
using namespace std; 


void string_permutation(string& original, string& perm, ostream& outfile);
 
int main() {
	string original = "ABCD";		//Four letters represents the four cities not including Reno
	string perm;   
	ofstream outfile;
	outfile.open("Possible_Routes.txt");

	string_permutation(original,perm, outfile);
 	outfile.close();
 	
 	Graph g(5);
	add_vertex(0, 0);		//Reno
	add_vertex(0, 704);		//Seattle
	add_vertex(0, -439);		//Las Vegas
	add_vertex(518, 0);		//Salt Lake City
	add_vertex(-218, 0);		//San Francisco
 
	return 0;
}


void string_permutation(string& original, string& perm, ostream& outfile) {
	if(original.empty()) {
		char array[6];
		strcpy(array,perm.c_str());
		outfile << "Reno -> ";
		for(int cnt = 0; cnt < 4; cnt++) {
			switch(array[cnt]) {
				case 'A':
					outfile << "San Francisco -> ";
					break;
				case 'B':
					outfile << "Salt Lake City -> ";
					break;
				case 'C':
					outfile << "Seattle -> ";
					break;
				case 'D':
					outfile << "Las Vegas -> ";
					break;
			}
		}
		outfile << "Reno" << endl;
		cout << perm << endl;
		return;
	}
 
	for(int i=0;i < original.size();++i) {
		string original2 = original;
		original2.erase(i,1);
		string perm2 = perm;
		perm2 += original.at(i);
		string_permutation(original2,perm2, outfile);
	} 
}




