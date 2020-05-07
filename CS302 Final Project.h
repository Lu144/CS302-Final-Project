




#include <iostream>
//#include <vector>
#include <string>
#include <bits/stdc++.h>
//#include "Salesman.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
using namespace std; 


void string_permutation(string& original, string& perm, ostream& outfile);
string brute_force(string& original, string& perm, int shortest_dis);
int distance_between(char I, char J);

int main() {
	string original = "ABCD";		//Four letters represents the four cities not including Reno
	string perm, result;   
	char print[5];
	int distance = 1000;
	ofstream outfile;
	outfile.open("Possible_Routes.txt");
	outfile << "The possible routes are: " << endl << endl;
	string_permutation(original,perm, outfile);
	
	//Graph stuff
	result = brute_force(original, perm, distance);
	
	strcpy(print,result.c_str());
	
	for(int p =0; p<4 ; p++) {
		cout << print[p];
	}
	
 	outfile.close();
 
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


string brute_force(string& original, string& perm, int shortest_dis) {	//Where shortest_dis is set to arbitrarily high number
	if(original.empty()) {
		int distance = 0;
		char array[6], prev = 'X';		//X = Reno to start
		strcpy(array,perm.c_str());
		for(int cnt = 0; cnt < 4; cnt++) {
			if(prev == 'X') {
				distance += distance_between(prev,array[cnt]);
				prev = array[cnt];
			}
			switch(array[cnt]) {
				case 'A':
					distance += distance_between(prev,array[cnt]);
					prev = 'A';
					break;
				case 'B':
					distance += distance_between(prev,array[cnt]);
					prev = 'B';
					break;
				case 'C':
					distance += distance_between(prev,array[cnt]);
					prev = 'C';
					break;
				case 'D':
					distance += distance_between(prev,array[cnt]);
					prev = 'D';
					break;
			}
		}  
		distance += distance_between(prev,'X');
		if(distance < shortest_dis) {
			shortest_dis = distance;
			return perm;
		}
	}
 
	for(int i=0;i < original.size();++i) {
		string original2 = original;
		original2.erase(i,1);
		string perm2 = perm;
		perm2 += original.at(i);
		brute_force(original2,perm2, shortest_dis);
	} 
}


int distance_between(char I, char J) {
	if(((I=='X')&&(J=='A')) || ((J=='X')&&(I=='A'))) {
		return 218;
	}
	else if(((I=='X')&&(J=='B')) || ((J=='X')&&(I=='B'))) {
		return 518;
	}
	else if(((I=='X')&&(J=='C')) || ((J=='X')&&(I=='C'))) {
		return 704;
	}
	else if(((I=='X')&&(J=='D')) || ((J=='X')&&(I=='D'))) {
		return 439;
	}
	else if(((I=='A')&&(J=='B')) || ((J=='A')&&(I=='B'))) {
		return 736;
	}
	else if(((I=='A')&&(J=='C')) || ((J=='A')&&(I=='C'))) {
		return 808;
	}
	else if(((I=='A')&&(J=='D')) || ((J=='A')&&(I=='D'))) {
		return 569;
	}
	else if(((I=='B')&&(J=='C')) || ((J=='B')&&(I=='C'))) {
		return 830;
	}
	else if(((I=='B')&&(J=='D')) || ((J=='B')&&(I=='D'))) {
		return 421;
	}
	else {
		return 1125;
	}

}



