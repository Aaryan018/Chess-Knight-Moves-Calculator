//TestKnight.cpp file
//Description: This class finds the shortest path of a knight from one postion to another
//Author: Aaryan Gupta


#include<iostream>
#include<vector>

using namespace std;


//each node represents each vertex of path
class Node{

	public:

		bool check = false;

		int x;
		int y;
		
		int dist = 1000;

		int predx;
		int predy;
		
};


//this function finds if the given coordinates is the legit next neighboiur or not
bool isNeighbour(int x, int y, vector<Node> v){

	if(x < 0 || y < 0 || x > 7 || y > 7){
		return false;
	}

	for(int i = 0; i < (int)v.size(); i++){
		if(v[i].x == x && v[i].y == y){
			return false;
		}
	}


	return true;
}


//this function finds the node with minimum distance and marks it true.
Node findMinNode(vector<Node> &v){

	int min = 1000000;
	int index = 0;

	for(int i = 0; i < (int)v.size(); i++){
		if(v[i].dist < min && v[i].check == false){
			min = v[i].dist;
			index = i;
		}
	}


	v[index].check = true;
	return v[index];


}

//this function checks if the destination node is marked check or not.
bool distChecked(vector<Node> v, Node dest){

	for(int i = 0; i < (int)v.size(); i++){
		if(v[i].x == dest.x && v[i].y == dest.y && v[i].check == true){
			return true;
		}
	}

	return false;

}

// it finds simplest possible path to get from one square to another by outputting all squares the knight will stop on along
void knight_moves(Node src, Node dest){


	int neighx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int neighy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	vector<Node> v;
	v.push_back(src);

	int tempx, tempy;
	Node tempNode = src;


	while(dest.check == false){

		for(int i = 0; i < 8; i++){
			tempx = tempNode.x + neighx[i];
			tempy = tempNode.y + neighy[i];

			//isNeighbour function
			if(isNeighbour(tempx, tempy, v)){
				Node n;
				n.x = tempx;
				n.y = tempy;
				n.predx = tempNode.x;
				n.predy = tempNode.y;
				n.dist = tempNode.dist + 1;
				v.push_back(n);
			}

		}
		
		tempNode = findMinNode(v);


		if(distChecked(v, dest)){
			dest.check = true;
		}
	}

	string str = "";
	int index;

	//checker
	for(int i = 0; i < (int)v.size(); i++){
		if(v[i].x == dest.x && v[i].y == dest.y){
			cout << "Number of moves: " << v[i].dist << endl;
			index = i;
			break;
		}
	}

	while(v[index].x != v[index].predx && v[index].y != v[index].predy){

		str = to_string(v[index].x) + "," + to_string(v[index].y) + "\n" + str;

		for(int i = 0; i < (int)v.size(); i++){
			if(v[index].predx == v[i].x && v[index].predy == v[i].y){
				index = i;
			}
		}
	}

	str = to_string(v[index].x) + "," + to_string(v[index].y) + "\n" + str;
	cout << str;

}


//main function that inputs the source and destination from user and finds the shortest path
int main(){

	Node src;
	cout << "Enter current location: ";
	cin >> src.x;
	cin >> src.y;
	src.predx = src.x;
	src.predy = src.y;
	src.dist = 0;
	src.check = true;
	

	Node dest;
	cout << "Enter destination location: ";
	cin >> dest.x;
	cin >> dest.y;

	knight_moves(src, dest);
}


