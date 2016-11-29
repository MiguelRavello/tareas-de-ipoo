#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<map>
#include<vector>
#include<stdexcept>

using namespace std;

class Graph {
private:
	map<int, vector<int> > m_outgoing;
public:
	Graph(const vector<int> &startPoints, const vector<int> &endPoints){
		if(startPoints.size() != endPoints.size()){
			throw invalid_argument("el conjunto de llegada es diferente al inicio");
		}
		for(int i=0;i<startPoints.size();i++){
			int start=startPoints[i];
			int end=endPoints[i];
			m_outgoing[start].push_back(end);
			m_outgoing[end];
		}
	}
	
	int numOutgoing(const int nodeID) const{
		return adjacent(nodeID).size();
	}
	
	const vector<int> &adjacent(const int nodeID) const{
		map<int, vector<int> >::const_iterator i= m_outgoing.find(nodeID);
		if(i==m_outgoing.end()) {
			throw invalid_argument("nodo invalido");
		}
		return i->second;
	}
};

#endif

