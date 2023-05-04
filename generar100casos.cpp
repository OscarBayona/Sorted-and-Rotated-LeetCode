#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

// Función que genera un vector aleatorio de tamaño n
vector<int> randomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Función que rota un vector k veces a la izquierda
vector<int> rotateArray(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> rotatedArr(n);
    for (int i = 0; i < n; i++) {
        rotatedArr[(i + n - k) % n] = arr[i];
    }
    return rotatedArr;
}

// Función que alterna entre 3 métodos para devolver un array en cada caso de prueba
vector<int> generateTestCase(int n) {
    int choice = rand() % 3;
    if (choice == 0) {
        // Generar un array aleatorio
        return randomArray(n);
    } else if (choice == 1) {
        // Generar un array ordenado y rotado
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            int num = rand() % 2;
            arr[i] = i+num;
        }
        int k = rand() % n;
        return rotateArray(arr, k);
    } else {
        // Generar un array ordenado
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            int num = rand() % 2;
            arr[i] = i+num;
        }
        return arr;
    }
}

//leetcode solution
bool check(vector<int>& nums) {
    int rotaciones=0;
    if (nums[nums.size()-1]>nums[0]) rotaciones++;
    for(int i=0; i<nums.size()-1;i++){
        if (nums[i]>nums[i+1]) rotaciones++;
        if(rotaciones>=2) return false;
    }
    
    return true;
}

int main() {
    srand(time(NULL));
    int n = 0;
    // Abrir el archivo de texto para escribir
    ofstream output("test_cases.txt");
    output << 100 << endl;
    for (int i = 0; i < 100; i++) {
        n = rand() % 100 + 1;
        vector<int> arr = generateTestCase(n);
        cout << "Caso " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cout << arr[j] << " ";
            output << arr[j] << " ";
        }
        cout << endl;
        output << endl;
        cout << "Resultado: "<< check(arr);
        cout << endl;
    }
    output.close();
    return 0;
}
