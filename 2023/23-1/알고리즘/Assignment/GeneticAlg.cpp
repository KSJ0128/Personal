#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

// 개선 요소: 랜덤 단일 교차 -> 랜덤 다점 교차, 돌연변이 확률 변화(초기엔 70%, 중기엔 20%, 이후엔 10% 확률, 개체 수의 6~7% 발생), 난수 생성법 변화, 개체 수 1000-> 1500(2000 이상은 메모리 오버플로우 발생하는 듯)

// GA 매개 변수
const int MAX_V = 500; // 최대 정점 개수
const int MAX_E = 5000;   // 최대 간선 개수
const int POPULATION_SIZE = 1500; // 개체 집단 크기
const int TIME_LIMIT = 179; // 제한 시간

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> two(0, 1);
uniform_int_distribution<int> hund(0, 99);
uniform_int_distribution<int> pSize(0, POPULATION_SIZE-1);

struct Edge {
    int s; // 출발
    int d; // 도착
    int w; // 가중치
};

// 개체 구조
struct Individual {
    int chromosome[MAX_V]; // 최대 정점 개수 = MAX_V
    int fitness;
};

// 그래프 정보
Edge edges[MAX_E]; // 최대 간선 개수 = MAX_E
int v; // # of 정점
int e; // # of 간선

// 개체 집단을 초기화하는 함수
void initializePopulation(Individual population[]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < v; j++) {
            population[i].chromosome[j] = two(gen); // 0 또는 1로 초기화
        }
        population[i].fitness = 0; // 적합도 0으로 초기화
    }
}

// 개체의 적합도(가중치 합)를 계산하는 함수
void calculateFitness(Individual& individual) {
    int totalWeight = 0;
    for (int i = 0; i < e; i++) { // 간선 개수 만큼
        if (individual.chromosome[edges[i].s] != individual.chromosome[edges[i].d]) { // [s] == 0, [d] == 1이면 가중치합 +w
            totalWeight += edges[i].w;
        }
    }
    individual.fitness = totalWeight; // 개체 적합도 가중치 합으로 업데이트
}

// 개체를 비교하여 더 우수한 개체(가중치가 더 큰 것)를 반환하는 함수
Individual compareIndividuals(const Individual& individual1, const Individual& individual2) { // 최적해, 현재 개체
    if (individual1.fitness > individual2.fitness) { // 적합도(가중치 합) 비교
        return individual1;
    } else {
        return individual2;
    }
}

// 두 개체를 교차하는 함수, 다점 교차
Individual crossover(const Individual& parent1, const Individual& parent2) {
    Individual child;
    uniform_int_distribution<int> ver(0, v-1);

    int crossoverPoint1 = ver(gen); // 0 ~ 정점 개수 - 1, 어느 지점까지 crossover 적용할지
    int crossoverPoint2 = ver(gen); // 0 ~ 정점 개수 - 1, 어느 지점까지 crossover 적용할지

    // 첫 번째 부분을 부모 1로부터 복사
    for (int i = 0; i < crossoverPoint1; i++) { // 자식의 0 ~ crossoverPoint-1 까지 parent1의 정점 정보 입력
        child.chromosome[i] = parent1.chromosome[i];
    }

    // 두 번째 부분을 부모 2로부터 복사
    for (int i = crossoverPoint1; i < crossoverPoint2; i++) { // 자식의 crossoverPoint ~ 정점 개수-1 까지 parent2의 정점 정보 입력
        child.chromosome[i] = parent2.chromosome[i];
    }

    // 세 번째 부분을 부모 1로부터 복사
    for (int i = crossoverPoint2; i < v; i++) { // 자식의 crossoverPoint ~ 정점 개수-1 까지 parent2의 정점 정보 입력
        child.chromosome[i] = parent1.chromosome[i];
    }

    return child;
}

// 개체를 돌연변이시키는 함수
void mutate(Individual& individual) {
    for(int i = 0; i < v/15; i++) // 개체 수의 6~7%에 돌연변이 발생
    {
        uniform_int_distribution<int> ver(0, v-1);
        int mutationPoint = ver(gen); // 어느 지점을 mutationPoint으로 지정
        individual.chromosome[mutationPoint] = 1 - individual.chromosome[mutationPoint]; // 비트 반전, 선택 여부 교환
    }
}

int main() {
    
    // 그래프 정보를 파일로부터 입력받기
    ifstream inputFile("maxcut.in");
    ofstream outputFile("maxcut.out");
    
    if (!inputFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    // 정점 개수와 간선 개수 입력 받기
    inputFile >> v >> e; // 파일의 맨 첫 줄

    // 간선 정보 입력 받기
    for (int i = 0; i < e; i++) {
        inputFile >> edges[i].s >> edges[i].d >> edges[i].w;
    }
    inputFile.close();

    // 개체 집단 생성 및 초기화
    Individual population[POPULATION_SIZE];
    Individual bestIndividual; // 최적해
    initializePopulation(population);

        // 시작 시간 기록
        time_t startTime = time(nullptr); 

        // 유전 알고리즘 반복
        while (true) { // crossover&mutation 거친 newPopulation으로 업데이트 후 최적해 초기화 반복
            // 개체 적합도(가중치 합) 계산, 모든 개체
            for (int i = 0; i < POPULATION_SIZE; i++) {
                calculateFitness(population[i]);
            }

            // 현재 개체가 최적해보다 우수하다면 최적해 업데이트, 적합도 비교
            bestIndividual = population[0];
            for (int i = 1; i < POPULATION_SIZE; i++) {
                bestIndividual = compareIndividuals(bestIndividual, population[i]);
            }

            // 새로운 개체 집단 생성
            Individual newPopulation[POPULATION_SIZE];

            // 개체 선택, 교차, 돌연변이 수행
            for (int i = 0; i < POPULATION_SIZE; i++) {
                // 개체 선택 (토너먼트 선택)
                int parentIndex1 = pSize(gen); // 0 ~ POPULATION_SIZE-1
                int parentIndex2 = pSize(gen); // 0 ~ POPULATION_SIZE-1

                Individual parent1 = population[parentIndex1]; // 부모1 랜덤 선택
                Individual parent2 = population[parentIndex2]; // 부모2 랜덤 선택

                // Crossover
                Individual child = crossover(parent1, parent2); // 랜덤 선택한 부모1, 2 crossover

                // Mutation
                if(i < POPULATION_SIZE/10)
                {
                    if (hund(gen) < 70) { // 초기엔 70% 확률로 돌연변이 발생
                        mutate(child);
                    }
                }
                else if(i < POPULATION_SIZE/5)
                {
                    if (hund(gen) < 20) { // 중기엔 20% 확률로 돌연변이 발생
                        mutate(child);
                    }
                }
                else
                {
                    if (hund(gen) < 10) { // 이후엔 10% 확률로 돌연변이 발생
                        mutate(child);
                    }
                }

                // 새로운 개체 집단에 추가
                newPopulation[i] = child;
            }

            // 새로운 개체 집단으로 업데이트
            for (int i = 0; i < POPULATION_SIZE; i++) {
                population[i] = newPopulation[i];
            }

            // 제한 시간 체크
            time_t currentTime = time(nullptr);

            if (currentTime - startTime >= TIME_LIMIT) {
                break; // 제한 시간을 초과하면 반복 종료
            }
        }

        // 최적해 출력
        for (int i = 0; i < v; i++) {
            if (bestIndividual.chromosome[i] == 1) {
                outputFile << i + 1 << " ";
            }
        }

        outputFile << endl;
        outputFile.close();
        return 0;
}