#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

// GA �Ű� ����
const int MAX_V = 500; // �ִ� ���� ����
const int MAX_E = 5000;   // �ִ� ���� ����
const int POPULATION_SIZE = 1500; // ��ü ���� ũ��
const int TIME_LIMIT = 179; // ���� �ð�

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> two(0, 1);
uniform_int_distribution<int> hund(0, 99);
uniform_int_distribution<int> pSize(0, POPULATION_SIZE - 1);

struct Edge {
    int s; // ���
    int d; // ����
    int w; // ����ġ
};

// ��ü ����
struct Individual {
    int chromosome[MAX_V]; // �ִ� ���� ���� = MAX_V
    int fitness;
};

// �׷��� ����
Edge edges[MAX_E]; // �ִ� ���� ���� = MAX_E
int v; // # of ����
int e; // # of ����

// ��ü ������ �ʱ�ȭ�ϴ� �Լ�
void initializePopulation(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < v; j++) {
            population[i].chromosome[j] = two(gen); // 0 �Ǵ� 1�� �ʱ�ȭ
        }
        population[i].fitness = 0; // ���յ� 0���� �ʱ�ȭ
    }
}

// ��ü�� ���յ�(����ġ ��)�� ����ϴ� �Լ�
void calculateFitness(Individual& individual) {
    int totalWeight = 0;
    for (int i = 0; i < e; i++) { // ���� ���� ��ŭ
        if (individual.chromosome[edges[i].s] != individual.chromosome[edges[i].d]) { // [s] == 0, [d] == 1�̸� ����ġ�� +w
            totalWeight += edges[i].w;
        }
    }
    individual.fitness = totalWeight; // ��ü ���յ� ����ġ ������ ������Ʈ
}

// ��ü�� ���Ͽ� �� ����� ��ü(����ġ�� �� ū ��)�� ��ȯ�ϴ� �Լ�
Individual compareIndividuals(const Individual& individual1, const Individual& individual2) { // ������, ���� ��ü
    if (individual1.fitness > individual2.fitness) { // ���յ�(����ġ ��) ��
        return individual1;
    }
    else {
        return individual2;
    }
}

// �� ��ü�� �����ϴ� �Լ�, ���� ����
Individual crossover(const Individual& parent1, const Individual& parent2) {
    Individual child;
    uniform_int_distribution<int> ver(0, v - 1);

    int crossoverPoint1 = ver(gen); // 0 ~ ���� ���� - 1, ��� �������� crossover ��������
    int crossoverPoint2 = ver(gen); // 0 ~ ���� ���� - 1, ��� �������� crossover ��������

    // ù ��° �κ��� �θ� 1�κ��� ����
    for (int i = 0; i < crossoverPoint1; i++) { // �ڽ��� 0 ~ crossoverPoint-1 ���� parent1�� ���� ���� �Է�
        child.chromosome[i] = parent1.chromosome[i];
    }

    // �� ��° �κ��� �θ� 2�κ��� ����
    for (int i = crossoverPoint1; i < crossoverPoint2; i++) { // �ڽ��� crossoverPoint ~ ���� ����-1 ���� parent2�� ���� ���� �Է�
        child.chromosome[i] = parent2.chromosome[i];
    }

    // �� ��° �κ��� �θ� 1�κ��� ����
    for (int i = crossoverPoint2; i < v; i++) { // �ڽ��� crossoverPoint ~ ���� ����-1 ���� parent2�� ���� ���� �Է�
        child.chromosome[i] = parent1.chromosome[i];
    }

    return child;
}

// ��ü�� �������̽�Ű�� �Լ�
void mutate(Individual& individual) {
    for (int i = 0; i < v / 15; i++) // ��ü ���� 6~7%�� �������� �߻�
    {
        uniform_int_distribution<int> ver(0, v - 1);
        int mutationPoint = ver(gen); // ��� ������ mutationPoint���� ����
        individual.chromosome[mutationPoint] = 1 - individual.chromosome[mutationPoint]; // ��Ʈ ����, ���� ���� ��ȯ
    }
}

void localSearch(Individual& bestIndividual, int v)
{
    bool improved = true;
    int iWeight = bestIndividual.fitness;

    while(improved) {
        improved = false;
        for(int i = 0; i < v; i++)
        {
            Individual localIndividual = bestIndividual;
            localIndividual.chromosome[i] = 1 - localIndividual.chromosome[i];
            calculateFitness(localIndividual);
            if(localIndividual.fitness - iWeight > 0) {
                bestIndividual = localIndividual;
                iWeight = localIndividual.fitness;
                improved = true;
            }
        }
    }
}

int main() {

    // ���� �ð� ���
    time_t startTime = time(nullptr);

    // �׷��� ������ ���Ϸκ��� �Է¹ޱ�

    ifstream inputFile("unweighted_100.in.txt");
    ofstream outputFile("unweighted_100.out.txt");

    if (!inputFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    // ���� ������ ���� ���� �Է� �ޱ�
    inputFile >> v >> e; // ������ �� ù ��

    // ���� ���� �Է� �ޱ�
    for (int i = 0; i < e; i++) {
        inputFile >> edges[i].s >> edges[i].d >> edges[i].w;
    }
    inputFile.close();

    // ��ü ���� ���� �� �ʱ�ȭ
    Individual population[POPULATION_SIZE];
    Individual bestIndividual; // ������
    initializePopulation(population);

    // ���� �˰����� �ݺ�
    while (true) { // crossover&mutation ��ģ newPopulation���� ������Ʈ �� ������ �ʱ�ȭ �ݺ�
        // ��ü ���յ�(����ġ ��) ���, ��� ��ü
        for (int i = 0; i < POPULATION_SIZE; i++) {
            calculateFitness(population[i]);
        }

        // ���� ��ü�� �����غ��� ����ϴٸ� ������ ������Ʈ, ���յ� ��
        bestIndividual = population[0];
        for (int i = 1; i < POPULATION_SIZE; i++) {
            bestIndividual = compareIndividuals(bestIndividual, population[i]);
        }

        // local Search
        localSearch(bestIndividual, v); 

        // ���ο� ��ü ���� ����
        Individual newPopulation[POPULATION_SIZE];

        // ��ü ����, ����, �������� ����
        for (int i = 0; i < POPULATION_SIZE; i++) {
            // ��ü ���� (��ʸ�Ʈ ����)
            int parentIndex1 = pSize(gen); // 0 ~ POPULATION_SIZE-1
            int parentIndex2 = pSize(gen); // 0 ~ POPULATION_SIZE-1

            Individual parent1 = population[parentIndex1]; // �θ�1 ���� ����
            Individual parent2 = population[parentIndex2]; // �θ�2 ���� ����

            // Crossover
            Individual child = crossover(parent1, parent2); // ���� ������ �θ�1, 2 crossover

            // Mutation
            if (i < POPULATION_SIZE / 10)
            {
                if (hund(gen) < 70) { // �ʱ⿣ 70% Ȯ���� �������� �߻�
                    mutate(child);
                }
            }
            else if (i < POPULATION_SIZE / 5)
            {
                if (hund(gen) < 20) { // �߱⿣ 20% Ȯ���� �������� �߻�
                    mutate(child);
                }
            }
            else
            {
                if (hund(gen) < 10) { // ���Ŀ� 10% Ȯ���� �������� �߻�
                    mutate(child);
                }
            }


            // ���ο� ��ü ���ܿ� �߰�
            newPopulation[i] = child;
        }

        // ���ο� ��ü �������� ������Ʈ
        for (int i = 0; i < POPULATION_SIZE; i++) {
            population[i] = newPopulation[i];
        }

        // ���� �ð� üũ
        time_t currentTime = time(nullptr);

        if (currentTime - startTime >= TIME_LIMIT) {
            break; // ���� �ð��� �ʰ��ϸ� �ݺ� ����
        }
    }

    // ������ ���
    for (int i = 0; i < v; i++) {
        if (bestIndividual.chromosome[i] == 1) {
            outputFile << i + 1 << " ";
        }
    }

    outputFile << endl;
    outputFile.close();

    calculateFitness(bestIndividual);
    std::cout << bestIndividual.fitness;

    return 0;
}