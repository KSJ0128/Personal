#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#define MAX 891
using namespace std;

class Queue
{
    int front;
    int rear;
    double que[MAX];
    double boucher[MAX] = {0.0};

    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(double price, int pClass)
    {
        if(pClass == 2)
            que[++rear] = price;
    }

    double dequeue()
    {
        return que[++front];
    }

    void check()
    {
        for(int i = 0; i <= rear; i++)
        {
            double price = dequeue(); // pop된 ticket price

            for(int j = front + 1; j <= rear; j++)
            {
                if(price >= que[j]) // 뒤의 티켓가가 더 작은 경우 해당 티켓가 * 0.1 = 바우처
                {
                    boucher[i] = que[j] * 0.1;
                    break;
                }
            }
        }
    }

    void print()
    {
        for(int i = 0; i <= rear; i++)
        {
            cout << boucher[i] << " ";
        }
    }
};

class TitanicData {
public:
    TitanicData() {}

    void read_data(string file_path) {
        ifstream input_file(file_path);
        if (!input_file.is_open()) {
            cerr << "Failed to open input file" << endl;
            return;
        }

        // Count number of data rows
        int num_rows = 0;
        string line;
        while (getline(input_file, line)) {
            num_rows++;
        }
        input_file.clear();
        input_file.seekg(0, ios::beg);

        // Allocate memory for data arrays
        nums_ = new int[num_rows];
        names_ = new string[num_rows];
        survived_ = new bool[num_rows];
        pclasses_ = new int[num_rows];
        sexes_ = new string[num_rows];
        fares_ = new double[num_rows];
        dist_to_toffi_ = new int[num_rows];
        speed_ = new int[num_rows];

        // Read data rows and store in arrays
        int i = 0;
        while (getline(input_file, line)) {
            stringstream ss(line);
            string cell;
            int j = 0;
            while (getline(ss, cell, ',')) {
                if (j == 0) {
                    nums_[i] = stoi(cell);
                }
                else if (j == 1) {
                    //survived_[i] = stoi(cell);
                    names_[i] = cell;
                }
                else if (j == 2) {
                    //pclasses_[i] = stoi(cell);
                    survived_[i] = stoi(cell);
                }
                else if (j == 3) {
                    //sexes_[i] = cell;
                    pclasses_[i] = stoi(cell);
                }
                else if (j == 4) {
                    //fares_[i] = stod(cell);
                    sexes_[i] = cell;
                }
                else if(j == 5) {
                    // ticket price
                    fares_[i] = stod(cell);
                }
                else if (j == 6) {
                    dist_to_toffi_[i] = stod(cell);
                }
                else if (j == 7) {
                    speed_[i] = stod(cell);
                }
                j++;
            }
            i++;
        }

        input_file.close();
        num_rows_ = num_rows;
    }

    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << nums_[i] << "," << names_[i] << "," << survived_[i] << "," << pclasses_[i] << "," << sexes_[i] << "," << fares_[i] << "," << dist_to_toffi_[i] << "," << speed_[i] << endl;
        }
    }

    void print_third() {

        int distance[MAX];
        for (int i = 0; i < num_rows_; i++) {

            if(pclasses_[i] == 3)
            {
                cout << dist_to_toffi_[i] << "," << speed_[i] << endl;
            }
        }
    }

    ~TitanicData() {
        delete[] nums_;
        delete[] names_;
        delete[] survived_;
        delete[] pclasses_;
        delete[] sexes_;
        delete[] fares_;
        delete[] dist_to_toffi_;
        delete[] speed_;
    }

    double setBoucher(Queue que)
    {
        for(int i = 0; i < 891; i++)
            que.enqueue(fares_[i], pclasses_[i]);
        que.check();
        que.print();
    }
private:
    int* nums_;
    string* names_;
    bool* survived_;
    int* pclasses_;
    string* sexes_;
    double* fares_;
    int* dist_to_toffi_;
    int* speed_;
    int num_rows_;
};



int main() {
    TitanicData data;
    Queue que;

    data.read_data("titanic.csv");
    //data.print_third();

    data.setBoucher(que);

    return 0;
}
 