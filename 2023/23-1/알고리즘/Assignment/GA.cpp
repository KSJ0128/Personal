
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

const int MAX_V = 500;
const int MAX_E = 5000;
int adj[MAX_V + 1][MAX_V + 1];
int weight[MAX_V + 1];
bool visited[MAX_V + 1];
double mutationProb = 0.1; // 돌연변이 확률
vector<vector<int>> population;
vector <int> fitness;
int popSize = 100;


int V; // numer of vertices
int E; // number of edges
int offspring; // 자손
vector<int> p1; // 부모1
vector<int> p2; // 부모2
	
	
	int random(int min, int max) {
		return min + rand() % (max - min + 1);
	}

    void init() { // 초기화
    population.resize(popSize, vector<int>(V));

    // 무작위로 초기화
    
    for (int i = 0; i < popSize; i++) {
        for (int j = 0; j < V; j++) {
            population[i][j] = random(0, 1);
        }
    }
}
	
	vector<int> tournamentSelect(int k){ // 토너먼트 선발
		random(0, V - 1); // 무슨 의미?
		vector<int> select(k);
		for (int i = 0; i < k; i++) { // K번(2번) 반복
			int idx = random(0, V - 1); // 0 - V-1 사이 난수 발생
			for (int j = 0; j < 4; j++) { // 4번 반복, 그 이유? 토너먼트가 두 번이라
				int idx2 = random(0, V - 1); // 0 - V-1 사이 난수 발생
				if (fitness[idx2] < fitness[idx]) { // 현재 개체와 이전 개체를 비교해 더 우수한 개체 인덱스 갱신 // fitness에 무엇이 들어있는지
					idx = idx2;
				}
			}
			select[i] = idx; // 두 개의 인덱스 추려 벡터에 저장
		}
		
		return select;
	}
	
	vector<int> tournamentCrossover(vector<int> p1,vector<int> p2){ // 토너먼트에서 이긴 애들끼리 교차
		int point = random(0, V - 1); //crossover 지점
		vector<int> parent(V);
		for (int i = 0; i < point; i++) {
			parent[i] = p1[i];
		}
		for (int i = point; i < V; i++) {
			parent[i] = p2[i];
		}
		
		return parent;
	}
	
	void mutation(vector<int> S){ // 돌연변이
		
		for (int i = 0; i < V; i++) {
			if (static_cast<double>(random(0.0, 1.0)) < mutationProb) {
				S[i] = 1 - S[i];
			}
		}
	}
	void replacement() { // 대치
			vector<int> offspring;
			// 대치를 위한 개체 교체
			int idx = tournamentSelect(1)[0];
			population[idx] = offspring;
	}
	void GA() { //genetic algorithm
		for (int i = 0; i < V; i++) { // 정점 개수 만큼 반복
			// 토너먼트 선발
			vector<int> p = tournamentSelect(2); // 두 개의 인덱스 추림
			vector <int> p1 = population[p[0]]; // p1 = 토너먼트 선발 1번째 인덱스
			vector <int> p2 = population[p[1]]; // p2 = 토너먼트 선발 2번째 인덱스

			// 토너먼트 교차
			vector <int> offspring = tournamentCrossover(p1, p2);

			// 돌연변이
			mutation(offspring);

			replacement();
		}
	}


int main(){
	ifstream fin("unweighted_50.txt");
	int V, E; // 정점 개수, 엣지 개수
	fin >> V >> E;
	int f, t, w;

	for (int i = 0; i < E; i++) {
		fin >> f >> t >> w; // 첫번째 정점, 두번째 정점, 가중치 // 어디에 활용?
	}
	
	GA();

	ofstream fout("unweighted_50.out.txt");

	// 최적 집합 출력
	vector<int> best = population[min_element(fitness.begin(), fitness.end()) - fitness.begin()];
	for (int i = 0; i < V; i++) {
		if (best[i] == 1) {
			fout << i + 1 << " ";
		}
	}
	fout << endl;

	fin.close();
	fout.close();

	return 0;
}