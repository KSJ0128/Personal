#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

struct Edge {
    int source;      //��� ����
    int target;      //���� ����
    int weight;      //����ġ
};

struct Individual {
    std::vector<int> partition;         //partition[0] : S ����, partition[1] : S' ����
    int fitness;                        //��ü�� ������ ���� ����ġ�� ����
};

typedef std::vector<std::vector<Edge>> Graph;    //2���� ����, 2���� ������ ��Ī�� Graph�̴�.

// �����ϰ� �� �������� ���� ����
Individual generateRandomSolution(int numVertices) {
    Individual individual;
    individual.partition.resize(numVertices + 1);
    for (int i = 1; i <= numVertices; i++) {
        individual.partition[i] = rand() % 2;            //partition ���ҿ� 0, 1 �ο�. ������ 2���� �׷����� ������ ����
    }
    individual.fitness = 0;                              //�ʱ� ���յ� 0���� ����
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

// �� ���� ���� �ع��� �����Ͽ� ���ο� ���� �ع��� �����ϴ� �Լ�
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

// ���� �ع��� �������̽��� ���̵� ���� �ع��� �����ϴ� �Լ�
void mutate(Individual& individual, double mutationRate) {
    int numVertices = individual.partition.size() - 1;
    for (int i = 1; i <= numVertices; i++) {
        if ((double)rand() / RAND_MAX < mutationRate) {
            individual.partition[i] = 1 - individual.partition[i];
        }
    }
}

// ���� �˰������� Max-cut ������ Ǫ�� �Լ�
Individual solveMaxCut(const Graph& graph, int populationSize, int maxGenerations, double crossoverRate, double mutationRate) {
    srand(time(nullptr));

    int numVertices = graph.size() - 1;
    int currentGeneration = 0;

    // �ʱ� �ع� ����
    std::vector<Individual> population;
        for (int i = 0; i < populationSize; i++) {
            Individual individual = generateRandomSolution(numVertices);
            individual.fitness = calculateFitness(graph, individual);
            population.push_back(individual);
        }

    // ���� �ݺ�
    while (currentGeneration < maxGenerations) {
        currentGeneration++;

        // ���յ� ������� ���� �ع� ����
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

        // ���� �� ��������
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

        // ���ο� ����� ������Ʈ
        population = newPopulation;
    }

    // ���� �ع� ����
    Individual bestSolution = population[0];
    for (int i = 1; i < populationSize; i++) {
        if (population[i].fitness > bestSolution.fitness) {
            bestSolution = population[i];
        }
    }

    return bestSolution;
}

int main() {
    // Max-cut ���� �ذ�
    int populationSize = 50;
    int maxGenerations = 1000;
    double crossoverRate = 0.8;
    double mutationRate = 0.01;

    // �׷��� ������ �о��
    std::ifstream inputFile("maxcut.in");
    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    Graph graph(numVertices + 1); // �׷��� �ʱ�ȭ

    // ���� ������ �׷����� ����
    for (int i = 0; i < numEdges; i++) {
        int source, target, weight;
        inputFile >> source >> target >> weight;
        Edge edge{ source, target, weight };
        graph[source].push_back(edge);
        graph[target].push_back(edge);
    }

    inputFile.close();

    Individual solution = solveMaxCut(graph, populationSize, maxGenerations, crossoverRate, mutationRate);

    // ���� �ع� ���
    std::cout << "���� �ع�: ";
    for (int i = 1; i < solution.partition.size(); i++) {
        if (solution.partition[i] == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "���� ����ġ ����: " << solution.fitness << std::endl;

    return 0;
}







