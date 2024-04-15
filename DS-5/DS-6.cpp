#include<iostream>
#include <cassert>
using namespace std;
class HashTaple {
private:
    string* HTtable;
    int* indexStatus;
    int length;
    int HTSize;
public:
    HashTaple(int size = 101) {
        assert(size > 0);
        HTtable = new string[size];
        indexStatus = new int[size];
        length = 0;
        HTSize = size;
        for (int i = 0; i < HTSize; i++)
        {
            indexStatus[i] = 0;
        }
    }
    void insert(int hashIndex, const string& rec) {
        int Pcount = 0;
        int Inc = 1;
        while (indexStatus[hashIndex] == 1 and HTtable[hashIndex] != rec and Pcount < HTSize) {
            Pcount++;
            hashIndex = (hashIndex + Inc) % HTSize;
            Inc++;
        }
        if (indexStatus[hashIndex] != 1)
        {
            HTtable[hashIndex] = rec;
            indexStatus[hashIndex] = 1;
            length++;
        }
    }
    bool searsh(int& hashIndex, const string& rec) {
        int Pcount = 0;
        while (indexStatus[hashIndex] != 0 and HTtable[hashIndex] != rec and Pcount < HTSize) {
            Pcount++;
            hashIndex = hashIndex + 1 % HTSize;
        }
        return(indexStatus[hashIndex] == 1 and HTtable[hashIndex] == rec);
    }
    HashTaple(const HashTaple& obj) {
        HTSize = obj.HTSize;
        length = 0;
        HTtable = new string[HTSize];
        indexStatus = new int[HTSize];
        for (int i = 0; i < HTSize; i++)
        {
            if (obj.indexStatus[i] == 1)
            {
                this->HTtable[i] = obj.HTtable[i];
                this->indexStatus[i] = 1;
            }
            else
                this->indexStatus[i] = 0;
        }
    }
    HashTaple operator =(const HashTaple& obj)
    {
        if (this->HTtable != NULL)
            delete[]HTtable;
        if (this->indexStatus != NULL)
            delete[]indexStatus;
        this->HTSize = obj.HTSize;
        this->length = 0;
        this->HTtable = new string[HTSize];
        this->indexStatus = new int[HTSize];
        for (int i = 0; i < HTSize; i++)
        {
            if (obj.indexStatus[i] == 1)
            {
                this->HTtable[i] = obj.HTtable[i];
                this->indexStatus[i] = 1;
            }
            else
                this->indexStatus[i] = 0;
        }
        return *this;
    }
    bool operator ==(const HashTaple& obj)
    {
        if (this->length != obj.length || this->HTSize != obj.HTSize)
            return false;
        for (int i = 0; i < this->length; i++)
        {
            if (this->indexStatus[i] != obj.indexStatus[i])
                return false;
        }
        for (int i = 0; i < this->HTSize and this->indexStatus[i] == 1; i++) {
            if (this->HTtable[i] != obj.HTtable[i])
                return false;
        }
        return true;
    }
    void print() {
        for (int i = 0; i < HTSize; i++)
        {
            if (indexStatus[i] != 0)
            {
                cout << "(" << i << ", " << HTtable[i] << "), ";
            }
        }
        cout << endl;
    }
    ~HashTaple() {
        delete[] HTtable;
        delete[]indexStatus;
    }
};
int hashFunction(string key, int size)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        if (key.at(i) >= 'A' and key.at(i) <= 'Z')
            sum += int(key.at(i));
        else
            sum += int(key.at(i));
    }
    return  sum % 101;
}
bool testCopyConst() {
    HashTaple x(101);
    int k1 = hashFunction("fares1", 101);
    int k2 = hashFunction("fares2", 101);
    int k3 = hashFunction("fares3", 101);
    int k4 = hashFunction("fares4", 101);
    int k5 = hashFunction("fares5", 101);
    int k6 = hashFunction("fares6", 101);
    int k7 = hashFunction("fares7", 101);
    int k8 = hashFunction("fares8", 101);
    int k9 = hashFunction("fares9", 101);
    int k10 = hashFunction("fares10", 101);
    x.insert(k1, "fares1");
    x.insert(k2, "fares2");
    x.insert(k3, "fares3");
    x.insert(k4, "fares4");
    x.insert(k5, "fares5");
    x.insert(k6, "fares6");
    x.insert(k7, "fares7");
    x.insert(k8, "fares8");
    x.insert(k9, "fares9");
    x.insert(k10, "fares10");
    HashTaple y = x;
    if (x == y)
        return true;
    else
        return false;
}
bool testAssignment() {
    HashTaple x(101);
    int k1 = hashFunction("fares1", 101);
    int k2 = hashFunction("fares2", 101);
    int k3 = hashFunction("fares3", 101);
    int k4 = hashFunction("fares4", 101);
    int k5 = hashFunction("fares5", 101);
    int k6 = hashFunction("fares6", 101);
    int k7 = hashFunction("fares7", 101);
    int k8 = hashFunction("fares8", 101);
    int k9 = hashFunction("fares9", 101);
    int k10 = hashFunction("fares10", 101);
    x.insert(k1, "fares1");
    x.insert(k2, "fares2");
    x.insert(k3, "fares3");
    x.insert(k4, "fares4");
    x.insert(k5, "fares5");
    x.insert(k6, "fares6");
    x.insert(k7, "fares7");
    x.insert(k8, "fares8");
    x.insert(k9, "fares9");
    x.insert(k10, "fares10");
    HashTaple y;
    y = x;
    if (x == y)
        return true;
    else
        return false;
}
int main() {
    HashTaple x;
    int k1 = hashFunction("fares1", 101);
    int k2 = hashFunction("fares2", 101);
    int k3 = hashFunction("fares3", 101);
    int k4 = hashFunction("fares4", 101);
    int k5 = hashFunction("fares5", 101);
    int k6 = hashFunction("fares6", 101);
    int k7 = hashFunction("fares7", 101);
    int k8 = hashFunction("fares8", 101);
    int k9 = hashFunction("fares9", 101);
    int k10 = hashFunction("fares10", 101);
    x.insert(k1, "fares1");
    x.insert(k2, "fares2");
    x.insert(k3, "fares3");
    x.insert(k4, "fares4");
    x.insert(k5, "fares5");
    x.insert(k6, "fares6");
    x.insert(k7, "fares7");
    x.insert(k8, "fares8");
    x.insert(k9, "fares9");
    x.insert(k10, "fares10");
    HashTaple y = x;
    HashTaple d(101);
    x.print();
    cout << endl;
    d = x;
    d.print();
}