#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

const int MAX_V = 100; // 최대 정점 개수
const int MAX_E = 1000; // 최대 간선 개수

int V; // 정점 개수
int E; // 간선 개수
std::vector<std::pair<int, int>> edges; // 간선 정보
std::vector<int> population; // 개체 집단
std::vector<int> bestSolution; // 최적해
int populationSize = 100; // 개체 집단 크기
int numGenerations = 100; // 세대 수

// 랜덤한 실수 값 반환 (0 <= x < 1)
double randomDouble() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

// 랜덤한 정수 값 반환 (min <= x <= max)
int randomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// 초기 개체 집단 생성
void initializePopulation() {
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(randomInt(0, 1));
    }
}

// 개체의 적합도 계산 (Max-Cut 문제 평가 함수)
int evaluateFitness(const std::vector<int>& solution) {
    int fitness = 0;
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        if (solution[u] != solution[v]) {
            fitness++;
        }
    }
    return fitness;
}

// 선택 연산 (룰렛 휠 선택)
int rouletteWheelSelection(const std::vector<int>& fitnesses) {
    int totalFitness = 0;
    for (int fitness : fitnesses) {
        totalFitness += fitness;
    }

    double randomValue = randomDouble() * totalFitness;
    double cumulativeFitness = 0.0;

    for (int i = 0; i < populationSize; ++i) {
        cumulativeFitness += fitnesses[i];
        if (cumulativeFitness >= randomValue) {
            return i;
        }
    }

    return populationSize - 1;
}

// 교차 연산 (한점 교차)
std::vector<int> onePointCrossover(const std::vector<int>& parent1, const std::vector<int>& parent2) {
    int crossoverPoint = randomInt(1, V - 1);
    std::vector<int> offspring(V);
    std::copy(parent1.begin(), parent1.begin() + crossoverPoint, offspring.begin());
    std::copy(parent2.begin() + crossoverPoint, parent2.end(), offspring.begin() + crossoverPoint);
    return offspring;
}

// 돌연변이 연산을 수행하는 함수
void mutation(std::vector<int>& solution, double mutationProb) {
    for (int i = 0; i < solution.size(); ++i) {
        if (randomDouble() < mutationProb) {
            solution[i] = 1 - solution[i]; // 유전 정보를 변이시킴
        }
    }
}

// 한 세대의 진화를 수행하는 함수
void evolve(std::vector<std::vector<int>>& population, double mutationProb) {
    std::vector<std::vector<int>> newPopulation;
    int populationSize = population.size();

    // 개체 집단의 크기만큼 진화를 수행
    for (int i = 0; i < populationSize; ++i) {
        // 선택 연산을 통해 부모 개체 선택
        int parentIndex1 = rouletteWheelSelection(fitnesses);
        int parentIndex2 = rouletteWheelSelection(fitnesses);
        std::vector<int> parent1 = population[parentIndex1];
        std::vector<int> parent2 = population[parentIndex2];

        // 교차 연산을 통해 자손 생성
        std::vector<int> offspring = onePointCrossover(parent1, parent2);

        // 돌연변이 연산 수행
        mutation(offspring, mutationProb);

        // 새로운 개체 집단에 추가
        newPopulation.push_back(offspring);
    }

    // 개체 집단 갱신
    population = newPopulation;
}

// 유전 알고리즘 실행 함수
void runGeneticAlgorithm() {
    // 초기 개체 집단 생성
    initializePopulation();

    for (int generation = 0; generation < numGenerations; ++generation) {
        // 개체의 적합도 계산
        std::vector<int> fitnesses;
        for (const auto& solution : population) {
            int fitness = evaluateFitness(solution);
            fitnesses.push_back(fitness);
        }

        // 진화 수행
        evolve(population, mutationProb);
        
        // 현재 세대의 최적해 탐색
        int bestFitness = -1;
        std::vector<int> bestSolution;
        for (const auto& solution : population) {
            int fitness = evaluateFitness(solution);
            if (fitness > bestFitness) {
                bestFitness = fitness;
                bestSolution = solution;
            }
        }

        // 현재 세대의 결과 출력
        std::cout << "Generation: " << generation << ", Best Fitness: " << bestFitness << std::endl;
    }
}
