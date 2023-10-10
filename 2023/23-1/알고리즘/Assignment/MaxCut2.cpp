#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Edge {
    int source;      //출발 정점
    int target;      //도착 정점
    int weight;      //가중치
};

struct Individual {
    std::vector<int> partition;         //partition[0] : S 집합, partition[1] : S' 집합
    int fitness;                        //개체가 가지는 간선 가중치의 총합
};

typedef std::vector<std::vector<Edge>> Graph;    //2차원 벡터, 2차원 벡터의 별칭은 Graph이다.

// 랜덤하게 두 집합으로 정점 분할
Individual generateRandomSolution(int numVertices) {
    Individual individual;
    individual.partition.resize(numVertices + 1);
    for (int i = 1; i <= numVertices; i++) {
        individual.partition[i] = rand() % 2;            //partition 원소에 0, 1 부여. 정점을 2개의 그룹으로 무작위 분할
    }
    individual.fitness = 0;                              //초기 적합도 0으로 설정
    return individual;
}

int calculateFitness(const Graph& graph, const Individual& individual) {
    int fitness = 0;
    for (const auto& edges : graph) {
        for (const auto& edge : edges) {
            if (individual.partition[edge.source] != individual.partition[edge.target]) {
                fitness += edge.weight;
            }
        }
    }
    return fitness;
}

// 두 개의 개별 해법을 교차하여 새로운 개별 해법을 생성하는 함수
Individual crossover(const Individual& parent1, const Individual& parent2) {
    int numVertices = parent1.partition.size() - 1;
    Individual child;
    child.partition.resize(numVertices + 1);
    for (int i = 1; i <= numVertices; i++) {
        if (rand() % 2 == 0) {
            child.partition[i] = parent1.partition[i];
        }
        else {
            child.partition[i] = parent2.partition[i];
        }
    }
    child.fitness = 0;
    return child;
}

// 개별 해법을 돌연변이시켜 변이된 개별 해법을 생성하는 함수
void mutate(Individual& individual, double mutationRate) {
    int numVertices = individual.partition.size() - 1;
    for (int i = 1; i <= numVertices; i++) {
        if ((double)rand() / RAND_MAX < mutationRate) {
            individual.partition[i] = 1 - individual.partition[i];
        }
    }
}

// 유전 알고리즘으로 Max-cut 문제를 푸는 함수
Individual solveMaxCut(const Graph& graph, int populationSize, int maxGenerations, double crossoverRate, double mutationRate) {
    srand(time(nullptr));

    int numVertices = graph.size() - 1;
    int currentGeneration = 0;

    // 초기 해법 생성
    std::vector<Individual> population;
        for (int i = 0; i < populationSize; i++) {
            Individual individual = generateRandomSolution(numVertices);
            individual.fitness = calculateFitness(graph, individual);
            population.push_back(individual);
        }

    // 세대 반복
    while (currentGeneration < maxGenerations) {
        currentGeneration++;

        // 적합도 기반으로 개별 해법 선택
        std::vector<Individual> selectedPopulation;
        for (int i = 0; i < populationSize; i++) {
            int index1 = rand() % populationSize;
            int index2 = rand() % populationSize;
            Individual parent1 = population[index1];
            Individual parent2 = population[index2];
            if (parent1.fitness > parent2.fitness) {
                selectedPopulation.push_back(parent1);
            }
            else {
                selectedPopulation.push_back(parent2);
            }
        }

        // 교차 및 돌연변이
        std::vector<Individual> newPopulation;
        for (int i = 0; i < populationSize; i++) {
            Individual parent1 = selectedPopulation[i];
            if ((double)rand() / RAND_MAX < crossoverRate) {
                int index2 = rand() % populationSize;
                Individual parent2 = selectedPopulation[index2];
                Individual child = crossover(parent1, parent2);
                mutate(child, mutationRate);
                child.fitness = calculateFitness(graph, child);
                newPopulation.push_back(child);
            }
            else {
                parent1.fitness = calculateFitness(graph, parent1);
                newPopulation.push_back(parent1);
            }
        }

        // 새로운 세대로 업데이트
        population = newPopulation;
    }

    // 최적 해법 선택
    Individual bestSolution = population[0];
    for (int i = 1; i < populationSize; i++) {
        if (population[i].fitness > bestSolution.fitness) {
            bestSolution = population[i];
        }
    }

    return bestSolution;
}

int main() {
    // Max-cut 문제 해결
    int populationSize = 50;
    int maxGenerations = 1000;
    double crossoverRate = 0.8;
    double mutationRate = 0.01;

    // 그래프 정보를 읽어옴
    std::ifstream inputFile("maxcut.in");
    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    Graph graph(numVertices + 1); // 그래프 초기화

    // 간선 정보를 그래프에 저장
    for (int i = 0; i < numEdges; i++) {
        int source, target, weight;
        inputFile >> source >> target >> weight;
        Edge edge{ source, target, weight };
        graph[source].push_back(edge);
        graph[target].push_back(edge);
    }

    inputFile.close();

    Individual solution = solveMaxCut(graph, populationSize, maxGenerations, crossoverRate, mutationRate);

    // 최적 해법 출력
    std::cout << "최적 해법: ";
    for (int i = 1; i < solution.partition.size(); i++) {
        if (solution.partition[i] == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "간선 가중치 총합: " << solution.fitness << std::endl;

    return 0;
}







