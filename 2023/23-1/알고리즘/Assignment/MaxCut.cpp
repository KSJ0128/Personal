#include <iostream>
#include <algorithm>
#include <random>
#include <tuple>
#include <utility>
#define V_MAX 500
#define V_HALF 250
#define V_QUARTER 50
#define E_MAX 5000
using namespace std;

void randomSelect(int sel[], int size) // 정점 랜덤 선택
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,size-1);

    for(int i = 0; i < size/2; i++)
    {
        sel[i] = dis(gen) + 1;

        for(int j = 0; j < i; j++)
        {
            if(sel[j] == sel[i])
                i--;
        }
    }
}

void wReset(pair<int,int> weight[], int v1, int v2, int w) // 정점과 관계된 간선들의 가중합 초기화
{
    get<0>(weight[v1-1]) += w; // 입력 받은 간선과 관계된 정점의 가중치 초기화
    get<0>(weight[v2-1]) += w; // 입력 받은 간선과 관계된 정점의 가중치 초기화
}

void calculateWeight(pair<int, int> weight[], tuple<int,int,int> e[], int sel[], int vNum, int eNum, int& wSum) // 선택된 정점 집합에 대한 가중합 계산
{
    vNum /= 2;

    for(int i = 0; i < eNum; i++)
    {
        int* v1 = find(sel, sel+vNum, get<0>(e[i]));
        int* v2 = find(sel, sel+vNum, get<1>(e[i]));

        if(v1 == (sel+vNum) && v2 != (sel+vNum))
        {
            wSum += get<2>(e[i]);
            wReset(weight, get<0>(e[i]), get<1>(e[i]), get<2>(e[i]));
        }
        else if(v1 != (sel+vNum) && v2 == (sel+vNum))
        {
            wSum += get<2>(e[i]);
            wReset(weight, get<0>(e[i]), get<1>(e[i]), get<2>(e[i]));
        }
    }
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void crossOver(int sel[], pair<int,int> w[], int vNum)
{
    int sel_i[V_QUARTER] = {0};
    int unSel_i[V_QUARTER] = {0};
    int sI = 0, uI = 0, wI = vNum-1;
    
    sort(w, w+vNum, compare); // pair 내림차순 정렬

    for(int i = 0; i < vNum; i++, wI--)
    {
        if(find(sel, sel+(vNum/2), get<1>(w[wI])) != sel+(vNum/2)) // 정점이 선택된 집합에 속할 경우
        {  
            if(sI < vNum/10)
                sel_i[sI++] = get<1>(w[wI]);
        }
        else // 정점이 선택된 집합에 속하지 않을 경우
        {
            if(uI < vNum/10)
                unSel_i[uI++] = get<1>(w[wI]);
        }

        if(sI == vNum/10 && uI == vNum/10)
            break;
    }

    for(int i = 0; i < vNum/10; i++) // swap
    {
        int* index = find(sel, sel+(vNum/2), sel_i[i]);
        *index = unSel_i[i];
    }
    
}

int main()
{
    tuple<int, int, int> edge[E_MAX];// 간선 집합
    int select_V[V_HALF] = {0}; // 선택된 정점의 집합
    int vNum, eNum, wSum, v1, v2, w; // 정점 개수, 간선 개수, 가중합

    cin >> vNum >> eNum; // 정점 개수, 간선 개수 입력

    for(int i = 0; i < eNum; i++) // 엣지 입력
    {
        cin >> v1 >> v2 >> w;
        get<0>(edge[i]) = v1;
        get<1>(edge[i]) = v2;
        get<2>(edge[i]) = w;
    }

    randomSelect(select_V, vNum); // 정점 랜덤 선택

    cout << "선택된 정점: ";

    for(int i = 0; i < vNum/2; i++)
    {
        cout << select_V[i] << " ";
    }

    for(int i = 0; i < 10; i++)
    {
        pair<int,int> weight[V_MAX]; // 정점과 연결된 간선의 가중합
        wSum = 0;

        for(int j = 0; j < vNum; j++) // pair 초기화
        {
            get<1>(weight[j]) = j+1;
        }

        calculateWeight(weight, edge, select_V, vNum, eNum, wSum); // 선택된 정점들에 대한 가중합 계산

        cout << "crossOver 전: " << wSum << endl;

        crossOver(select_V, weight, vNum); 

        wSum = 0;

        calculateWeight(weight, edge, select_V, vNum, eNum, wSum); // 선택된 정점들에 대한 가중합 계산

        cout << "선택된 정점: ";

        for(int i = 0; i < vNum/2; i++)
        {
            cout << select_V[i] << " ";
        }

        cout << "crossOver 후: " << wSum << endl;
    }
}

/*
10 14                     
1 10 1
1 8 1
2 10 -1
2 9 1
2 6 1
2 4 1
4 8 1
4 10 -1
5 9 1
5 10 -1
5 8 1
6 10 1
6 9 1
7 9 1
*/

/*
50 123 
1 21 1
1 49 1
1 3 1
1 32 1
2 15 1
2 6 1
2 29 1
2 4 1
3 36 1
3 27 1
3 23 1
4 13 1
4 36 1
4 19 1
5 43 1
5 21 1
5 19 1
5 20 1
6 40 1
6 22 1
6 24 1
6 18 1
6 34 1
6 44 1
6 10 1
7 38 1
7 37 1
7 23 1
7 17 1
8 13 1
8 20 1
8 34 1
8 30 1
8 25 1
8 35 1
9 48 1
9 47 1
9 15 1
10 20 1
10 47 1
10 44 1
11 41 1
11 35 1
11 26 1
11 40 1
11 18 1
12 25 1
12 18 1
12 26 1
13 21 1
13 15 1
13 39 1
13 34 1
14 26 1
14 36 1
15 35 1
15 16 1
15 41 1
15 39 1
15 47 1
15 24 1
16 28 1
16 31 1
16 30 1
16 50 1
16 44 1
16 21 1
16 42 1
17 33 1
17 35 1
17 37 1
18 37 1
18 48 1
18 35 1
18 34 1
19 46 1
19 29 1
20 30 1
20 50 1
21 29 1
21 40 1
21 42 1
21 44 1
22 49 1
22 42 1
23 33 1
24 37 1
24 34 1
24 31 1
25 38 1
25 29 1
26 42 1
26 47 1
26 46 1
26 50 1
27 41 1
27 40 1
27 38 1
28 40 1
28 38 1
29 47 1
29 39 1
29 41 1
29 38 1
30 45 1
31 44 1
32 39 1
37 49 1
38 44 1
38 47 1
38 39 1
38 40 1
38 48 1
39 43 1
39 47 1
40 46 1
41 47 1
42 46 1
42 50 1
44 46 1
46 47 1
46 49 1
47 48 1
*/

/*
100 495 
1 61 1
1 71 1
1 41 1
1 9 1
1 98 1
1 22 1
1 72 1
1 36 1
1 99 1
1 53 1
2 35 1
2 87 1
2 20 1
2 38 1
2 23 1
2 76 1
2 14 1
2 65 1
2 29 1
2 4 1
3 57 1
3 64 1
3 98 1
3 21 1
3 18 1
3 96 1
3 15 1
3 73 1
3 77 1
3 23 1
4 61 1
4 34 1
4 9 1
4 49 1
4 17 1
4 90 1
4 86 1
4 99 1
4 14 1
4 12 1
4 63 1
4 69 1
5 73 1
5 17 1
5 26 1
5 89 1
5 55 1
5 18 1
5 93 1
5 19 1
6 36 1
6 56 1
6 64 1
6 19 1
6 76 1
6 75 1
6 86 1
6 98 1
6 29 1
6 40 1
6 24 1
6 52 1
6 68 1
6 44 1
7 26 1
7 31 1
7 46 1
7 95 1
7 55 1
7 75 1
7 54 1
7 37 1
7 67 1
8 72 1
8 30 1
8 48 1
8 61 1
8 23 1
8 70 1
8 25 1
9 35 1
9 33 1
9 58 1
9 73 1
9 87 1
9 84 1
9 45 1
9 31 1
9 98 1
10 100 1
10 96 1
10 66 1
10 38 1
10 41 1
10 20 1
10 56 1
11 16 1
11 61 1
11 32 1
11 43 1
11 64 1
11 93 1
11 80 1
11 29 1
11 35 1
11 76 1
11 68 1
11 90 1
12 89 1
12 50 1
12 62 1
12 20 1
12 79 1
12 92 1
12 21 1
12 75 1
12 68 1
13 51 1
13 33 1
13 42 1
13 87 1
13 77 1
13 71 1
13 58 1
13 89 1
13 34 1
14 87 1
14 93 1
14 84 1
14 19 1
14 76 1
14 43 1
15 70 1
15 34 1
15 93 1
15 77 1
15 63 1
15 85 1
15 59 1
16 40 1
16 74 1
16 44 1
16 78 1
16 31 1
16 80 1
16 71 1
16 42 1
17 55 1
17 75 1
17 68 1
17 32 1
17 57 1
17 76 1
17 66 1
17 49 1
17 35 1
17 87 1
18 98 1
18 60 1
18 81 1
18 85 1
18 26 1
18 63 1
18 58 1
18 86 1
18 32 1
18 68 1
18 92 1
18 69 1
18 87 1
18 34 1
19 100 1
19 46 1
19 58 1
19 39 1
19 98 1
19 29 1
19 23 1
20 50 1
20 64 1
20 61 1
20 41 1
20 55 1
21 74 1
21 80 1
21 39 1
21 51 1
21 29 1
21 55 1
22 65 1
22 52 1
22 45 1
22 82 1
22 98 1
22 49 1
22 92 1
23 26 1
23 100 1
23 82 1
23 24 1
23 98 1
23 56 1
23 72 1
23 59 1
23 76 1
23 57 1
24 79 1
24 76 1
24 26 1
24 80 1
24 25 1
24 45 1
24 72 1
24 84 1
24 65 1
25 45 1
25 91 1
25 47 1
25 75 1
25 38 1
25 29 1
26 83 1
26 32 1
26 74 1
26 56 1
26 42 1
26 97 1
26 96 1
26 50 1
27 46 1
27 67 1
27 93 1
27 92 1
27 47 1
27 32 1
27 52 1
27 90 1
27 88 1
28 85 1
28 56 1
28 48 1
28 42 1
28 78 1
28 40 1
29 80 1
29 74 1
29 55 1
29 93 1
29 97 1
29 41 1
30 88 1
30 87 1
30 68 1
30 31 1
30 98 1
30 38 1
30 48 1
30 70 1
30 58 1
31 72 1
31 77 1
31 41 1
31 49 1
32 68 1
32 73 1
32 65 1
32 67 1
32 87 1
32 58 1
32 51 1
32 39 1
33 65 1
33 66 1
33 85 1
33 46 1
33 45 1
33 69 1
33 97 1
33 67 1
33 73 1
34 85 1
34 62 1
34 57 1
34 99 1
34 56 1
35 41 1
35 77 1
35 63 1
35 58 1
36 42 1
36 50 1
36 97 1
36 63 1
36 54 1
36 53 1
36 64 1
37 56 1
37 52 1
37 87 1
37 78 1
37 92 1
37 74 1
38 62 1
38 54 1
38 45 1
38 57 1
38 81 1
38 51 1
38 44 1
38 88 1
38 40 1
38 78 1
38 79 1
38 48 1
39 57 1
39 63 1
39 67 1
39 97 1
39 79 1
39 47 1
39 82 1
40 51 1
40 54 1
40 61 1
40 56 1
41 95 1
41 54 1
41 77 1
42 51 1
42 74 1
42 56 1
42 61 1
42 47 1
42 100 1
43 67 1
43 56 1
43 69 1
43 73 1
43 85 1
43 81 1
43 54 1
43 95 1
43 49 1
44 54 1
44 68 1
44 62 1
44 98 1
44 65 1
44 73 1
44 95 1
44 81 1
44 96 1
44 71 1
45 74 1
45 84 1
45 78 1
45 63 1
46 79 1
46 91 1
46 81 1
46 98 1
46 89 1
46 68 1
46 97 1
46 49 1
48 99 1
48 98 1
48 97 1
48 68 1
49 68 1
49 64 1
49 67 1
49 91 1
50 92 1
50 79 1
50 87 1
50 98 1
50 66 1
51 74 1
52 98 1
52 92 1
52 81 1
53 83 1
53 94 1
53 71 1
53 81 1
53 84 1
54 67 1
54 80 1
54 55 1
55 67 1
55 81 1
55 57 1
55 99 1
56 86 1
56 75 1
56 64 1
56 94 1
56 72 1
57 89 1
57 94 1
57 93 1
57 88 1
58 94 1
58 61 1
58 70 1
58 72 1
58 84 1
59 85 1
59 97 1
60 71 1
60 67 1
60 72 1
60 90 1
60 83 1
60 97 1
60 94 1
61 77 1
61 71 1
61 91 1
61 68 1
62 98 1
62 76 1
63 83 1
63 70 1
63 89 1
64 88 1
64 93 1
64 95 1
64 89 1
64 78 1
64 85 1
64 76 1
65 100 1
65 66 1
65 91 1
65 89 1
65 97 1
66 78 1
66 73 1
66 92 1
66 94 1
68 83 1
68 88 1
68 85 1
69 96 1
69 79 1
70 73 1
70 74 1
70 100 1
71 83 1
71 90 1
71 92 1
72 82 1
72 78 1
73 99 1
74 90 1
74 81 1
75 83 1
75 94 1
75 98 1
75 93 1
76 88 1
76 80 1
76 90 1
77 100 1
77 96 1
78 79 1
78 80 1
78 94 1
79 83 1
79 89 1
80 84 1
80 95 1
81 99 1
82 88 1
83 91 1
84 94 1
84 100 1
85 97 1
86 95 1
86 91 1
86 92 1
87 99 1
88 97 1
88 89 1
89 93 1
90 96 1
91 98 1
91 97 1
92 94 1
92 95 1
92 96 1
93 99 1
96 98 1
*/